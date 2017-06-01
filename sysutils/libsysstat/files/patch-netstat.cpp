--- netstat.cpp.orig	2016-12-10 23:50:29 UTC
+++ netstat.cpp
@@ -23,6 +23,23 @@
 **
 ** END_COMMON_COPYRIGHT_HEADER */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include <cstdio>
+
+#if defined(HAVE_SYSCTL_H) && defined(HAVE_IF_H)
+extern "C"
+{
+    #include <net/if.h>
+    #include <net/if_mib.h>
+    #include <net/if_types.h>
+    #include <sys/socket.h> /* PF_LINK */
+    #include <sys/types.h>
+    #include <sys/sysctl.h>
+}
+#endif
 
 #include "netstat.h"
 #include "netstat_p.h"
@@ -37,7 +54,7 @@ NetStatPrivate::NetStatPrivate(NetStat *
 
     connect(mTimer, SIGNAL(timeout()), SLOT(timeout()));
 
-
+#ifndef HAVE_SYSCTL_H
     QStringList rows(readAllFile("/proc/net/dev").split(QChar('\n'), QString::SkipEmptyParts));
 
     rows.erase(rows.begin(), rows.begin() + 2);
@@ -50,6 +67,30 @@ NetStatPrivate::NetStatPrivate(NetStat *
 
         mSources.append(tokens[0].trimmed());
     }
+#else
+    int count;
+    size_t len;
+    int cntifmib[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_SYSTEM, IFMIB_IFCOUNT };// net.link.generic.system.ifcount;
+    len = sizeof(int);
+    if (sysctl(cntifmib, 5, &count, &len, NULL, 0) < 0)
+        perror("sysctl");
+
+
+    struct ifmibdata ifmd;
+    size_t len1 = sizeof(ifmd);
+    for (int i=1; i<=count;i++) {
+        int name[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_IFDATA, i, IFDATA_GENERAL };
+
+        if (sysctl(name, 6, &ifmd, &len1, NULL, 0) < 0) {
+            perror("sysctl");
+        }
+        if ((ifmd.ifmd_data.ifi_type == IFT_ETHER) || (ifmd.ifmd_data.ifi_type == IFT_IEEE80211)) {
+        const char *iface = ifmd.ifmd_name;
+        mSources.append(QString::fromLatin1(iface));
+        }
+    }
+
+#endif
 }
 
 NetStatPrivate::~NetStatPrivate()
@@ -58,6 +99,50 @@ NetStatPrivate::~NetStatPrivate()
 
 void NetStatPrivate::timeout()
 {
+#if defined(HAVE_IF_H) && defined(HAVE_SYSCTL_H)
+    int count;
+    size_t len;
+    int name[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_SYSTEM, IFMIB_IFCOUNT };
+    struct ifmibdata ifmd;
+
+    len = sizeof(int);
+    if (sysctl(name, 5, &count, &len, NULL, 0) < 0)
+        return;
+
+    for (int i = 1; i <= count; i++)
+    {
+        len = sizeof(ifmd);
+        int name[] = { CTL_NET, PF_LINK, NETLINK_GENERIC, IFMIB_IFDATA, i, IFDATA_GENERAL };
+
+        if (sysctl(name, 6, &ifmd, &len, NULL, 0) < 0)
+            break;
+
+        if ((ifmd.ifmd_data.ifi_type == IFT_ETHER) || (ifmd.ifmd_data.ifi_type == IFT_IEEE80211))
+        {
+            const char *iface = ifmd.ifmd_name;
+            QString interfaceName = QString::fromLatin1(iface);
+            if ((ifmd.ifmd_data.ifi_link_state == LINK_STATE_UP) && (ifmd.ifmd_data.ifi_ipackets > 0))
+            {
+
+
+                Values current;
+                current.received = ifmd.ifmd_data.ifi_ibytes;
+                current.transmitted = ifmd.ifmd_data.ifi_obytes;
+
+                if (!mPrevious.contains(interfaceName))
+                    mPrevious.insert(interfaceName, Values());
+                const Values &previous = mPrevious[interfaceName];
+
+                if (interfaceName == mSource)
+                    emit update((( current.received - previous.received ) * 1000 ) / mTimer->interval(), (( current.transmitted - previous.transmitted ) * 1000 ) / mTimer->interval());
+
+                mPrevious[interfaceName] = current;
+            } else if(interfaceName == mSource)
+                emit(update(0,0));
+
+        }
+    }
+#else
     QStringList rows(readAllFile("/proc/net/dev").split(QChar('\n'), QString::SkipEmptyParts));
 
 
@@ -99,6 +184,7 @@ void NetStatPrivate::timeout()
 
         mPrevious[interfaceName] = current;
     }
+#endif
 }
 
 QString NetStatPrivate::defaultSource()

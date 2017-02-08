--- netstat.cpp.orig	2016-12-10 23:50:29 UTC
+++ netstat.cpp
@@ -23,6 +23,21 @@
 **
 ** END_COMMON_COPYRIGHT_HEADER */
 
+#include "config.h"
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
@@ -37,7 +52,7 @@ NetStatPrivate::NetStatPrivate(NetStat *
 
     connect(mTimer, SIGNAL(timeout()), SLOT(timeout()));
 
-
+#ifndef HAVE_SYSCTL_H
     QStringList rows(readAllFile("/proc/net/dev").split(QChar('\n'), QString::SkipEmptyParts));
 
     rows.erase(rows.begin(), rows.begin() + 2);
@@ -50,6 +65,7 @@ NetStatPrivate::NetStatPrivate(NetStat *
 
         mSources.append(tokens[0].trimmed());
     }
+#endif
 }
 
 NetStatPrivate::~NetStatPrivate()
@@ -58,6 +74,46 @@ NetStatPrivate::~NetStatPrivate()
 
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
+            if ((ifmd.ifmd_data.ifi_link_state == LINK_STATE_UP) && (ifmd.ifmd_data.ifi_ipackets > 0))
+            {
+                const char *iface = ifmd.ifmd_name;
+                QString interfaceName = QString::fromLatin1(iface);
+
+                Values current;
+                current.received = ifmd.ifmd_data.ifi_ibytes;
+                current.transmitted = ifmd.ifmd_data.ifi_obytes;
+
+                if (!mPrevious.contains(interfaceName))
+                    mPrevious.insert(interfaceName, Values());
+                const Values &previous = mPrevious[interfaceName];
+
+                emit update(((current.received - previous.received) * 1000) / mTimer->interval(), ((current.transmitted - previous.transmitted) * 1000) / mTimer->interval());
+
+                mPrevious[interfaceName] = current;
+            }
+        }
+    }
+#else
     QStringList rows(readAllFile("/proc/net/dev").split(QChar('\n'), QString::SkipEmptyParts));
 
 
@@ -99,6 +155,7 @@ void NetStatPrivate::timeout()
 
         mPrevious[interfaceName] = current;
     }
+#endif
 }
 
 QString NetStatPrivate::defaultSource()

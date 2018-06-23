--- cpustat.cpp.orig	2017-09-23 12:46:10 UTC
+++ cpustat.cpp
@@ -23,15 +23,68 @@
 **
 ** END_COMMON_COPYRIGHT_HEADER */
 
-
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 #include <unistd.h>
+#ifdef HAVE_SYSCTL_H
+extern "C"
+{
+    #include <stdlib.h>
+    #include <limits.h>
+    #include <string.h>
+    #include <sys/resource.h> /* CPUSTATES */
 
+    #include <sys/types.h>
+    #include <sys/sysctl.h>
+}
+#endif
 #include "cpustat.h"
 #include "cpustat_p.h"
 
 
 namespace SysStat {
 
+#ifdef HAVE_SYSCTL_H
+char *GetFirstFragment(char *string, const char *delim)
+{
+    char *token = NULL;
+
+    token = strsep(&string, delim);
+    if (token != NULL)
+    {
+        /* We need only the first fragment, so no loop! */
+        return token;
+    }
+    else
+        return NULL;
+}
+
+int GetCpu(void)
+{
+    static int mib[] = { CTL_HW, HW_NCPU };
+    int buf;
+    size_t len = sizeof(int);
+
+    if (sysctl(mib, 2, &buf, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return buf;
+}
+
+/* Frequence is in MHz */
+ulong CurrentFreq(void)
+{
+    ulong freq;
+    size_t len = sizeof(freq);
+
+    if (sysctlbyname("dev.cpu.0.freq", &freq, &len, NULL, 0) < 0)
+        return 0;
+    else
+        return freq;
+}
+#endif
+
 CpuStatPrivate::CpuStatPrivate(CpuStat *parent)
     : BaseStatPrivate(parent)
     , mMonitoring(CpuStat::LoadAndFrequency)
@@ -39,7 +92,10 @@ CpuStatPrivate::CpuStatPrivate(CpuStat *
     mSource = defaultSource();
 
     connect(mTimer, SIGNAL(timeout()), SLOT(timeout()));
-
+#ifdef HAVE_SYSCTL_H
+	size_t flen=2;
+	sysctlnametomib("kern.cp_times",mib,&flen);
+#endif
     mUserHz = sysconf(_SC_CLK_TCK);
 
     updateSources();
@@ -47,6 +103,49 @@ CpuStatPrivate::CpuStatPrivate(CpuStat *
 
 void CpuStatPrivate::addSource(const QString &source)
 {
+#ifdef HAVE_SYSCTL_H
+    char buf[1024];
+    char *tokens, *t;
+    ulong min = 0, max = 0;
+    size_t len = sizeof(buf);
+
+    /* The string returned by the dev.cpu.0.freq_levels sysctl
+     * is a space separated list of MHz/milliwatts.
+     */
+    if (sysctlbyname("dev.cpu.0.freq_levels", buf, &len, NULL, 0) < 0)
+        return;
+
+    t = strndup(buf, len);
+    if (t == NULL)
+    {
+        free(t);
+        return;
+    }
+
+    while ((tokens = strsep(&t, " ")) != NULL)
+    {
+        char *freq;
+        ulong res;
+
+        freq = GetFirstFragment(tokens, "/");
+        if (freq != NULL)
+        {
+            res = strtoul(freq, &freq, 10);
+            if (res > max)
+            {
+                max = res;
+            }
+            else
+            {
+                if ((min == 0) || (res < min))
+                    min = res;
+            }
+        }
+    }
+
+    free(t);
+    mBounds[source] = qMakePair(min, max);
+#else
     bool ok;
 
     uint min = readAllFile(qPrintable(QString("/sys/devices/system/cpu/%1/cpufreq/scaling_min_freq").arg(source))).toUInt(&ok);
@@ -56,11 +155,26 @@ void CpuStatPrivate::addSource(const QSt
         if (ok)
             mBounds[source] = qMakePair(min, max);
     }
+#endif
 }
 
 void CpuStatPrivate::updateSources()
 {
     mSources.clear();
+#ifdef HAVE_SYSCTL_H
+    int cpu;
+
+    cpu = GetCpu();
+    for (int i =0;i<cpu;i++)
+    {
+        mSources.append(QString("cpu%1").arg(i));
+
+
+
+        addSource(QString("cpu%1").arg(i));
+    }
+    mBounds.clear();
+#else
 
     foreach (const QString &row, readAllFile("/proc/stat").split(QChar('\n'), QString::SkipEmptyParts))
     {
@@ -97,6 +211,7 @@ void CpuStatPrivate::updateSources()
                 addSource(QString("cpu%1").arg(number));
         }
     }
+#endif
 }
 
 CpuStatPrivate::~CpuStatPrivate()
@@ -117,14 +232,98 @@ void CpuStatPrivate::recalculateMinMax()
 {
     int cores = 1;
     if (mSource == "cpu")
+#ifdef HAVE_SYSCTL_H
+		cores = mSources.size();
+#else
         cores = mSources.size() - 1;
-
+#endif
     mIntervalMin = static_cast<float>(mTimer->interval()) / 1000 * static_cast<float>(mUserHz) * static_cast<float>(cores) / 1.25; // -25%
     mIntervalMax = static_cast<float>(mTimer->interval()) / 1000 * static_cast<float>(mUserHz) * static_cast<float>(cores) * 1.25; // +25%
 }
 
 void CpuStatPrivate::timeout()
 {
+#ifdef HAVE_SYSCTL_H
+    if ( (mMonitoring == CpuStat::LoadOnly)
+      || (mMonitoring == CpuStat::LoadAndFrequency) )
+    {
+        size_t cp_size = sizeof(long) * CPUSTATES * GetCpu();
+        long *cp_times = (long *)malloc(cp_size);
+        Values current;
+        int cpuNumber = mSource.midRef(3).toInt();
+        if (sysctl(mib,2, cp_times, &cp_size, NULL, 0) < 0)
+            free(cp_times);
+
+        current.user = static_cast<ulong>(cp_times[CP_USER+cpuNumber*CPUSTATES]);
+        current.nice = static_cast<ulong>(cp_times[CP_NICE+cpuNumber*CPUSTATES]);
+        current.system = static_cast<ulong>(cp_times[CP_SYS+cpuNumber*CPUSTATES]);
+        current.idle = static_cast<ulong>(cp_times[CP_IDLE+cpuNumber*CPUSTATES]);
+        current.other = static_cast<ulong>(cp_times[CP_INTR+cpuNumber*CPUSTATES]);
+        current.total = current.user + current.nice + current.system+current.idle+current.other;
+
+        float sumDelta = static_cast<float>(current.total - mPrevious.total);
+
+        if ((mPrevious.total != 0) && ((sumDelta < mIntervalMin) || (sumDelta > mIntervalMax)))
+        {
+            if (mMonitoring == CpuStat::LoadAndFrequency)
+                emit update(0.0, 0.0, 0.0, 0.0, 0.0, 0);
+            else
+                emit update(0.0, 0.0, 0.0, 0.0, 0.0);
+
+            mPrevious.clear();
+        }
+        else
+        {
+            if (mMonitoring == CpuStat::LoadAndFrequency)
+            {
+                ulong freq = 0;
+
+                freq = CurrentFreq();
+                if (freq > 0)
+                {
+                    emit update(
+                        static_cast<float>(current.user - mPrevious.user ) / sumDelta,
+                        static_cast<float>(current.nice - mPrevious.nice ) / sumDelta,
+                        static_cast<float>(current.system - mPrevious.system ) / sumDelta,
+                        static_cast<float>(current.idle - mPrevious.idle ) / sumDelta,
+                        static_cast<float>(current.other - mPrevious.other ) / sumDelta,
+                        freq);
+                }
+                else
+                {
+                    emit update(
+                        static_cast<float>(current.user - mPrevious.user ) / sumDelta,
+                        static_cast<float>(current.nice - mPrevious.nice ) / sumDelta,
+                        static_cast<float>(current.system - mPrevious.system ) / sumDelta,
+                        static_cast<float>(current.idle - mPrevious.idle ) / sumDelta,
+                        static_cast<float>(current.other - mPrevious.other ) / sumDelta);
+                }
+            }
+            else
+            {
+
+                emit update(
+                    static_cast<float>(current.user - mPrevious.user ) / sumDelta,
+                    static_cast<float>(current.nice - mPrevious.nice ) / sumDelta,
+                    static_cast<float>(current.system - mPrevious.system ) / sumDelta,
+                    static_cast<float>(current.idle - mPrevious.idle ) / sumDelta,
+                    static_cast<float>(current.other - mPrevious.other ) / sumDelta);
+            }
+
+            mPrevious = current;
+        }
+
+        free(cp_times);
+    }
+    else
+    {
+        ulong freq = 0;
+
+        freq = CurrentFreq();
+        if (freq > 0)
+            emit update(freq);
+    }
+#else
     if ( (mMonitoring == CpuStat::LoadOnly)
       || (mMonitoring == CpuStat::LoadAndFrequency) )
     {
@@ -258,6 +457,7 @@ void CpuStatPrivate::timeout()
         }
         emit update(freq);
     }
+#endif
 }
 
 QString CpuStatPrivate::defaultSource()
@@ -301,10 +501,15 @@ CpuStat::CpuStat(QObject *parent)
 {
     impl = new CpuStatPrivate(this);
     baseimpl = impl;
-
+#ifdef HAVE_SYSCTL_H
+    connect(impl, SIGNAL(update(float,float,float,float,float,ulong)), this, SIGNAL(update(float,float,float,float,float,ulong)));
+    connect(impl, SIGNAL(update(float,float,float,float,float)), this, SIGNAL(update(float,float,float,float,float)));
+    connect(impl, SIGNAL(update(ulong)), this, SIGNAL(update(ulong)));
+#else
     connect(impl, SIGNAL(update(float,float,float,float,float,uint)), this, SIGNAL(update(float,float,float,float,float,uint)));
     connect(impl, SIGNAL(update(float,float,float,float)), this, SIGNAL(update(float,float,float,float)));
     connect(impl, SIGNAL(update(uint)), this, SIGNAL(update(uint)));
+#endif
 }
 
 CpuStat::~CpuStat()

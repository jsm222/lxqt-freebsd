--- plugin-sysstat/lxqtsysstat.cpp.orig	2017-01-01 22:27:14 UTC
+++ plugin-sysstat/lxqtsysstat.cpp
@@ -27,7 +27,6 @@
 
 #include "lxqtsysstat.h"
 #include "lxqtsysstatutils.h"
-
 #include <SysStat/CpuStat>
 #include <SysStat/MemStat>
 #include <SysStat/NetStat>
@@ -323,12 +322,20 @@ void LXQtSysStatContent::updateSettings(
                 if (mUseFrequency)
                 {
                     qobject_cast<SysStat::CpuStat*>(mStat)->setMonitoring(SysStat::CpuStat::LoadAndFrequency);
+#ifdef HAVE_SYSCTL_H
+                    connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float, float, float, ulong)), this, SLOT(cpuUpdate(float, float, float, float, float, ulong)));
+#else
                     connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float, float, float, uint)), this, SLOT(cpuUpdate(float, float, float, float, float, uint)));
+#endif
                 }
                 else
                 {
                     qobject_cast<SysStat::CpuStat*>(mStat)->setMonitoring(SysStat::CpuStat::LoadOnly);
-                    connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float, float)), this, SLOT(cpuUpdate(float, float, float, float)));
+#ifdef HAVE_SYSCTL_H
+                    connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float, float,float)), this, SLOT(cpuUpdate(float, float, float, float,float)));
+#else
+                    connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float,float)), this, SLOT(cpuUpdate(float, float, float,float)));
+#endif
                 }
             }
             else if (mDataType == "Memory")
@@ -385,7 +392,18 @@ void LXQtSysStatContent::clearLine()
     for (int i = 0; i < 100; ++i)
         reinterpret_cast<QRgb*>(mHistoryImage.scanLine(i))[mHistoryOffset] = bg;
 }
-
+#ifdef HAVE_SYSCTL_H
+void LXQtSysStatContent::cpuUpdate(float user, float nice, float system, float idle,float other, ulong freq)
+{
+    int y_system = static_cast<int>(system * 100.0);
+    int y_user   = static_cast<int>(user   * 100.0);
+    int y_nice   = static_cast<int>(nice   * 100.0);
+    int y_idle   = static_cast<int>(idle   * 100.0);
+    int y_other  = static_cast<int>(other  * 100.0);
+    int y_freq   = static_cast<int>(freq);
+    toolTipInfo(tr("system: %1%<br>user: %2%<br>nice: %3%<br>idle: %4%<br>other: %5%<br>freq: %6MHz", "CPU tooltip information")
+            .arg(y_system).arg(y_user).arg(y_nice).arg(y_idle).arg(y_other).arg(y_freq));
+#else
 void LXQtSysStatContent::cpuUpdate(float user, float nice, float system, float other, float frequencyRate, uint)
 {
     int y_system = static_cast<int>(system * 100.0 * frequencyRate);
@@ -396,7 +414,7 @@ void LXQtSysStatContent::cpuUpdate(float
 
     toolTipInfo(tr("system: %1%<br>user: %2%<br>nice: %3%<br>other: %4%<br>freq: %5%", "CPU tooltip information")
             .arg(y_system).arg(y_user).arg(y_nice).arg(y_other).arg(y_freq));
-
+#endif
     y_system = clamp(y_system, 0, 99);
     y_user   = clamp(y_user + y_system, 0, 99);
     y_nice   = clamp(y_nice + y_user  , 0, 99);
@@ -436,16 +454,26 @@ void LXQtSysStatContent::cpuUpdate(float
     update(0, mTitleFontPixelHeight, width(), height() - mTitleFontPixelHeight);
 }
 
+#ifdef HAVE_SYSCTL_H
+void LXQtSysStatContent::cpuUpdate(float user, float nice, float system, float idle,float other)
+#else
 void LXQtSysStatContent::cpuUpdate(float user, float nice, float system, float other)
+#endif
 {
     int y_system = static_cast<int>(system * 100.0);
     int y_user   = static_cast<int>(user   * 100.0);
     int y_nice   = static_cast<int>(nice   * 100.0);
+#ifdef HAVE_SYSCTL_H
+    int y_idle   = static_cast<int>(idle   * 100.0);
+#endif
     int y_other  = static_cast<int>(other  * 100.0);
-
+#ifdef HAVE_SYSCTL_H
+    toolTipInfo(tr("system: %1%<br>user: %2%<br>nice: %3%<br>idle: %4%<br>other: %5%<br>freq: n/a", "CPU tooltip information")
+            .arg(y_system).arg(y_user).arg(y_nice).arg(y_idle).arg(y_other));
+#else
     toolTipInfo(tr("system: %1%<br>user: %2%<br>nice: %3%<br>other: %4%<br>freq: n/a", "CPU tooltip information")
             .arg(y_system).arg(y_user).arg(y_nice).arg(y_other));
-
+#endif
     y_system = clamp(y_system, 0, 99);
     y_user   = clamp(y_user + y_system, 0, 99);
     y_nice   = clamp(y_nice + y_user, 0, 99);

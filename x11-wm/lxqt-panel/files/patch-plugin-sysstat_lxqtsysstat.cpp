--- plugin-sysstat/lxqtsysstat.cpp.orig	2017-01-01 22:27:14 UTC
+++ plugin-sysstat/lxqtsysstat.cpp
@@ -320,6 +320,7 @@ void LXQtSysStatContent::updateSettings(
         {
             if (mDataType == "CPU")
             {
+#if defined(Q_OS_LINUX)
                 if (mUseFrequency)
                 {
                     qobject_cast<SysStat::CpuStat*>(mStat)->setMonitoring(SysStat::CpuStat::LoadAndFrequency);
@@ -330,6 +331,10 @@ void LXQtSysStatContent::updateSettings(
                     qobject_cast<SysStat::CpuStat*>(mStat)->setMonitoring(SysStat::CpuStat::LoadOnly);
                     connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float, float)), this, SLOT(cpuUpdate(float, float, float, float)));
                 }
+#elif defined(Q_OS_FREEBSD)
+                qobject_cast<SysStat::CpuStat*>(mStat)->setMonitoring(SysStat::CpuStat::LoadOnly);
+                connect(qobject_cast<SysStat::CpuStat*>(mStat), SIGNAL(update(float, float, float, float, float)), this, SLOT(cpuUpdate(float, float, float, float, float)));
+#endif
             }
             else if (mDataType == "Memory")
             {
@@ -386,6 +391,7 @@ void LXQtSysStatContent::clearLine()
         reinterpret_cast<QRgb*>(mHistoryImage.scanLine(i))[mHistoryOffset] = bg;
 }
 
+#if defined(Q_OS_LINUX)
 void LXQtSysStatContent::cpuUpdate(float user, float nice, float system, float other, float frequencyRate, uint)
 {
     int y_system = static_cast<int>(system * 100.0 * frequencyRate);
@@ -478,6 +484,52 @@ void LXQtSysStatContent::cpuUpdate(float
 
     update(0, mTitleFontPixelHeight, width(), height() - mTitleFontPixelHeight);
 }
+#elif defined(Q_OS_FREEBSD)
+void LXQtSysStatContent::cpuUpdate(float user, float nice, float system, float idle, float other)
+{
+    int y_system = static_cast<int>(round(system * 100.0));
+    int y_user   = static_cast<int>(round(user   * 100.0));
+    int y_nice   = static_cast<int>(round(nice   * 100.0));
+    int y_idle   = static_cast<int>(round(idle   * 100.0));
+    int y_other  = static_cast<int>(round(other  * 100.0));
+
+    toolTipInfo(tr("system: %1%<br>user: %2%<br>nice: %3%<br>other: %4%", "CPU tooltip information")
+                .arg(y_system).arg(y_user).arg(y_nice).arg(y_other));
+
+
+    y_system = clamp(y_system, 0, 99);
+    y_user   = clamp(y_user + y_system, 0, 99);
+    y_nice   = clamp(y_nice+y_user, 0, 99);
+    y_other  = clamp(y_other+y_nice, 0, 99);
+
+    clearLine();
+    QPainter painter(&mHistoryImage);
+    if (y_system != 0)
+    {
+        painter.setPen(mColours.cpuSystemColour);
+        painter.drawLine(mHistoryOffset, y_system, mHistoryOffset, 0);
+    }
+    if (y_user != y_system)
+    {
+        painter.setPen(mColours.cpuUserColour);
+        painter.drawLine(mHistoryOffset, y_user, mHistoryOffset, y_system);
+    }
+    if (y_nice != y_user)
+    {
+        painter.setPen(mColours.cpuNiceColour);
+        painter.drawLine(mHistoryOffset, y_nice, mHistoryOffset, y_user);
+    }
+    if (y_other != y_nice)
+    {
+        painter.setPen(mColours.cpuOtherColour);
+        painter.drawLine(mHistoryOffset, y_other, mHistoryOffset, y_nice);
+    }
+
+    mHistoryOffset = (mHistoryOffset + 1) % width();
+
+    update(0, mTitleFontPixelHeight, width(), height() - mTitleFontPixelHeight);
+}
+#endif
 
 void LXQtSysStatContent::memoryUpdate(float apps, float buffers, float cached)
 {

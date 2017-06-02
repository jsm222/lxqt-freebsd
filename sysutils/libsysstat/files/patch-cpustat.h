--- cpustat.h.orig	2016-12-10 23:50:29 UTC
+++ cpustat.h
@@ -27,6 +27,11 @@
 #ifndef LIBSYSSTAT__CPU_STAT__INCLUDED
 #define LIBSYSSTAT__CPU_STAT__INCLUDED
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
+#include <cstdio>
 
 #include <QtCore/QObject>
 
@@ -35,6 +40,12 @@
 
 namespace SysStat {
 
+#ifdef HAVE_SYSCTL_H
+    char *GetFirstFragment(char *string, const char *delim);
+    int GetCpu(void);
+    ulong CurrentFreq(void);
+#endif
+
 class CpuStatPrivate;
 
 class SYSSTATSHARED_EXPORT CpuStat : public BaseStat
@@ -52,13 +63,23 @@ public:
 
     void updateSources();
 
+#ifdef HAVE_SYSCTL_H
     uint minFreq(const QString &source) const;
     uint maxFreq(const QString &source) const;
 
 signals:
-    void update(float user, float nice, float system, float other, float frequencyRate, uint frequency);
+    void update(float user, float nice, float system, float idle, float other, ulong frequency);
+    void update(float user, float nice, float system, float idle, float other);
+    void update(ulong frequency);
+#else
+    ulong minFreq(const QString &source) const;
+    ulong maxFreq(const QString &source) const;
+
+signals:
+    void update(float user, float nice, float system, float frequencyRate, uint frequency);
     void update(float user, float nice, float system, float other);
     void update(uint frequency);
+#endif
 
     void monitoringChanged(Monitoring);
 

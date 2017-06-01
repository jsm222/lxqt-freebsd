--- cpustat_p.h.orig	2016-12-10 23:50:29 UTC
+++ cpustat_p.h
@@ -27,6 +27,9 @@
 #ifndef LIBSYSSTAT__CPU_STAT__PRIVATE__INCLUDED
 #define LIBSYSSTAT__CPU_STAT__PRIVATE__INCLUDED
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
 
 #include <QtCore/QObject>
 #include <QtCore/QtGlobal>
@@ -52,6 +55,15 @@ public:
     CpuStat::Monitoring monitoring() const;
     void setMonitoring(CpuStat::Monitoring value);
 
+#ifdef HAVE_SYSCTL_H
+    ulong minFreq(const QString &source) const;
+    ulong maxFreq(const QString &source) const;
+
+signals:
+    void update(float user, float nice, float system, float idle, float other);
+    void update(ulong frequency);
+    void update(float user, float nice, float system, float idle, float other, ulong frequency);
+#else
     uint minFreq(const QString &source) const;
     uint maxFreq(const QString &source) const;
 
@@ -59,6 +71,7 @@ signals:
     void update(float user, float nice, float system, float other);
     void update(uint frequency);
     void update(float user, float nice, float system, float other, float frequencyRate, uint frequency);
+#endif
 
 private slots:
     void timeout();
@@ -74,22 +87,35 @@ private:
     {
         Values();
 
+#ifdef HAVE_SYSCTL_H
+        ulong user;
+        ulong nice;
+        ulong system;
+        ulong idle;
+        ulong other;
+        ulong total;
+#else
         qulonglong user;
         qulonglong nice;
         qulonglong system;
         qulonglong idle;
         qulonglong other;
         qulonglong total;
+#endif
 
         void sum();
 
         void clear();
     } Values;
     Values mPrevious;
-
+    int mib[2];
     CpuStat::Monitoring mMonitoring;
 
+#ifdef HAVE_SYSCTL_H
+    typedef QMap<QString, QPair<ulong, ulong> > Bounds;
+#else
     typedef QMap<QString, QPair<uint, uint> > Bounds;
+#endif
     Bounds mBounds;
 
     int mUserHz;

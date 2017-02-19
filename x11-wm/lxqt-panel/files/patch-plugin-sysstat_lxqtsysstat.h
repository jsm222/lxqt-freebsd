--- plugin-sysstat/lxqtsysstat.h.orig	2017-01-01 22:27:14 UTC
+++ plugin-sysstat/lxqtsysstat.h
@@ -137,8 +137,12 @@ protected:
     void resizeEvent(QResizeEvent *);
 
 protected slots:
+#if defined(Q_OS_LINUX)
     void cpuUpdate(float user, float nice, float system, float other, float frequencyRate, uint frequency);
     void cpuUpdate(float user, float nice, float system, float other);
+#elif defined(Q_OS_FREEBSD)
+    void cpuUpdate(float user, float nice, float system, float idle, float other);
+#endif
     void memoryUpdate(float apps, float buffers, float cached);
     void swapUpdate(float used);
     void networkUpdate(unsigned received, unsigned transmitted);

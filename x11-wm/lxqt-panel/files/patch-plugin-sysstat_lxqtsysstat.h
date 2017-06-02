--- plugin-sysstat/lxqtsysstat.h.orig	2017-01-01 22:27:14 UTC
+++ plugin-sysstat/lxqtsysstat.h
@@ -137,8 +137,13 @@ protected:
     void resizeEvent(QResizeEvent *);
 
 protected slots:
+/* moc only expands macros directly */
+#ifdef CMAKE_SYSTEM_NAME_LINUX
     void cpuUpdate(float user, float nice, float system, float other, float frequencyRate, uint frequency);
     void cpuUpdate(float user, float nice, float system, float other);
+#elif CMAKE_SYSTEM_NAME_FREEBSD
+    void cpuUpdate(float user, float nice, float system, float idle, float other);
+#endif
     void memoryUpdate(float apps, float buffers, float cached);
     void swapUpdate(float used);
     void networkUpdate(unsigned received, unsigned transmitted);

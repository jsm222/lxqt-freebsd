--- plugin-sysstat/lxqtsysstat.h.orig	2017-01-01 22:27:14 UTC
+++ plugin-sysstat/lxqtsysstat.h
@@ -30,7 +30,7 @@
 
 #include "../panel/ilxqtpanelplugin.h"
 #include "lxqtsysstatconfiguration.h"
-
+#include "config.h"
 #include <QLabel>
 
 
@@ -137,8 +137,16 @@ protected:
     void resizeEvent(QResizeEvent *);
 
 protected slots:
+#ifdef HAVE_SYSCTL_H
+    void cpuUpdate(float user, float nice, float system, float idle,float other, ulong freq);
+#else
     void cpuUpdate(float user, float nice, float system, float other, float frequencyRate, uint frequency);
-    void cpuUpdate(float user, float nice, float system, float other);
+#endif
+#ifdef HAVE_SYSCTL_H
+    void cpuUpdate(float user, float nice, float system, float idle,float other);
+#else
+    void cpuUpdate(float user, float nice, float system,float other);
+#endif
     void memoryUpdate(float apps, float buffers, float cached);
     void swapUpdate(float used);
     void networkUpdate(unsigned received, unsigned transmitted);

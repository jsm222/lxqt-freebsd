--- featherpad/x11.h.orig	2016-10-14 14:30:58 UTC
+++ featherpad/x11.h
@@ -20,7 +20,7 @@
 
 #include <QList>
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 #include <X11/Xlib.h>
 #endif
 

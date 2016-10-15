--- featherpad/x11.h.orig	2016-08-13 15:57:51 UTC
+++ featherpad/x11.h
@@ -18,9 +18,10 @@
 #ifndef X11_H
 #define X11_H
 
+#include <QtGlobal>
 #include <QList>
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 #include <X11/Xlib.h>
 namespace FeatherPad {
 QList<Window> listXWins (Window w);

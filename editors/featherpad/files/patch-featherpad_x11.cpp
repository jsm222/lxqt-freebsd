--- featherpad/x11.cpp.orig	2016-10-14 14:30:58 UTC
+++ featherpad/x11.cpp
@@ -18,7 +18,7 @@
 #include <QString>
 #include "x11.h"
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 #include <X11/Xatom.h>
 #include <QX11Info>
 #endif
@@ -35,7 +35,7 @@ long fromDesktop()
 {
     long res = -1;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
     Display  *disp = QX11Info::display();
     if (!disp) return res;
 
@@ -70,7 +70,7 @@ long onWhichDesktop (Window w)
 {
     long res = -1;
 
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
     Display *disp = QX11Info::display();
     if (!disp) return res;
 
@@ -105,7 +105,7 @@ long onWhichDesktop (Window w)
 
 bool isWindowShaded (Window window)
 {
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
     Display *disp = QX11Info::display();
     if (!disp) return false;
 
@@ -140,7 +140,7 @@ bool isWindowShaded (Window window)
 /*************************/
 void unshadeWindow (Window window)
 {
-#if defined Q_WS_X11 || defined Q_OS_LINUX
+#if defined Q_WS_X11 || defined Q_OS_LINUX || defined Q_OS_FREEBSD
     Display *disp = QX11Info::display();
     if (!disp) return;
 

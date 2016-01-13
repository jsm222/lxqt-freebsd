--- wayland_server.cpp.orig	2016-01-06 12:07:36 UTC
+++ wayland_server.cpp
@@ -274,7 +274,7 @@ void WaylandServer::initOutputs()
 int WaylandServer::createXWaylandConnection()
 {
     int sx[2];
-    if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sx) < 0) {
+    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sx) < 0) {
         qCWarning(KWIN_CORE) << "Could not create socket";
         return -1;
     }
@@ -300,7 +300,7 @@ void WaylandServer::destroyXWaylandConne
 int WaylandServer::createInputMethodConnection()
 {
     int sx[2];
-    if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sx) < 0) {
+    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sx) < 0) {
         qCWarning(KWIN_CORE) << "Could not create socket";
         return -1;
     }
@@ -320,7 +320,7 @@ void WaylandServer::destroyInputMethodCo
 void WaylandServer::createInternalConnection()
 {
     int sx[2];
-    if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sx) < 0) {
+    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sx) < 0) {
         qCWarning(KWIN_CORE) << "Could not create socket";
         return;
     }

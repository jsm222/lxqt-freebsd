--- autotests/wayland/kwin_wayland_test.cpp.orig	2016-01-06 12:07:35 UTC
+++ autotests/wayland/kwin_wayland_test.cpp
@@ -193,7 +193,7 @@ void WaylandTestApplication::startXwayla
         return;
     }
     int sx[2];
-    if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sx) < 0) {
+    if (socketpair(AF_UNIX, SOCK_STREAM, 0, sx) < 0) {
         std::cerr << "FATAL ERROR: failed to open socket to open XCB connection" << std::endl;
         exit(1);
         return;

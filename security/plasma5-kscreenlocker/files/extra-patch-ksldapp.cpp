The SOCK_CLOEXEC flag appears after revision r250154.

--- ksldapp.cpp.orig	2016-01-06 12:05:43 UTC
+++ ksldapp.cpp
@@ -558,7 +558,7 @@ void KSldApp::startLockProcess(Establish
 {
     if (m_isWayland && m_waylandDisplay) {
         int sx[2];
-        if (socketpair(AF_UNIX, SOCK_STREAM | SOCK_CLOEXEC, 0, sx) < 0) {
+        if (socketpair(AF_UNIX, SOCK_STREAM, 0, sx) < 0) {
             qWarning() << "Can not create socket";
             emit m_lockProcess->error(QProcess::FailedToStart);
             return;

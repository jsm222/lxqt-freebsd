--- sudo.cpp.orig	2015-11-02 05:06:33 UTC
+++ sudo.cpp
@@ -36,7 +36,13 @@
 #include <QSocketNotifier>
 #include <QDebug>
 #include <QThread>
+#if defined(__linux__)
 #include <pty.h>
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#include <libutil.h>
+#include <errno.h>
+#include <termios.h>
+#endif
 #include <unistd.h>
 #include <memory>
 #include <csignal>

--- lxqtapplication.cpp.orig	2015-11-02 07:12:49 UTC
+++ lxqtapplication.cpp
@@ -46,6 +46,7 @@ using namespace LXQt;
 #include <cstdio>
 #include <unistd.h>
 #include <cstring>
+#include <cerrno>
 #include <csignal>
 #include <sys/socket.h>
 #include <QDateTime>

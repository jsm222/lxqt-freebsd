--- featherpad/encoding.cpp.orig	2016-08-13 15:57:51 UTC
+++ featherpad/encoding.cpp
@@ -8,6 +8,7 @@
 
 #include <stdlib.h> // getenv
 #include <langinfo.h> // CODESET, nl_langinfo
+#include <locale.h>
 #include <stdint.h> // uint8_t, uint32_t
 #include <QTextCodec>
 #include "encoding.h"

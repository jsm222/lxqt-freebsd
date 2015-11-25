--- cmake/create_pkgconfig_file.cmake.orig	2014-10-21 15:47:40 UTC
+++ cmake/create_pkgconfig_file.cmake
@@ -25,5 +25,5 @@ macro (create_pkgconfig_file name desc r
             "\n"
         )
 
-    install(FILES ${_pkgfname} DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
+    install(FILES ${_pkgfname} DESTINATION ${CMAKE_INSTALL_PREFIX}/libdata/pkgconfig)
 endmacro()

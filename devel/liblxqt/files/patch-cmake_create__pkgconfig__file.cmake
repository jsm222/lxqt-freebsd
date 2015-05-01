--- cmake/create_pkgconfig_file.cmake.orig	2015-02-07 19:56:30 UTC
+++ cmake/create_pkgconfig_file.cmake
@@ -24,7 +24,7 @@ macro (create_pkgconfig_file name desc)
 
     # FreeBSD loves to install files to different locations
     # http://www.freebsd.org/doc/handbook/dirstructure.html
-    if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
+    if(${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" OR ${CMAKE_SYSTEM_NAME} MATCHES "DragonFly")
         install(FILES ${_pkgfname} DESTINATION libdata/pkgconfig)
     else()
         install(FILES ${_pkgfname} DESTINATION lib${LIB_SUFFIX}/pkgconfig)

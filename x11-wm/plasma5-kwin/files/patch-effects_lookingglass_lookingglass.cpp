Workaround for g++-4.8, error: 'log2' is not a member of 'std'.

--- effects/lookingglass/lookingglass.cpp.orig	2016-01-06 12:07:35 UTC
+++ effects/lookingglass/lookingglass.cpp
@@ -35,7 +35,7 @@ along with this program.  If not, see <h
 
 #include <kmessagebox.h>
 
-#include <cmath>
+#include <math.h>
 
 namespace KWin
 {
@@ -101,7 +101,7 @@ bool LookingGlassEffect::loadData()
     int texh = screenSize.height();
 
     // Create texture and render target
-    const int levels = std::log2(qMin(texw, texh)) + 1;
+    const int levels = log2(qMin(texw, texh)) + 1;
     m_texture = new GLTexture(GL_RGBA8, texw, texh, levels);
     m_texture->setFilter(GL_LINEAR_MIPMAP_LINEAR);
     m_texture->setWrapMode(GL_CLAMP_TO_EDGE);

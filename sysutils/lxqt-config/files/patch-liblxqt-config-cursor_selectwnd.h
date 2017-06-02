--- liblxqt-config-cursor/selectwnd.h.orig	2017-06-02 17:26:25 UTC
+++ liblxqt-config-cursor/selectwnd.h
@@ -15,16 +15,20 @@
 
 #include <QObject>
 #include <QWidget>
+#include <QPersistentModelIndex>
 #include <lxqtglobals.h>
 
 namespace LXQt {
   class Settings;
 }
 
+namespace Ui {
+class SelectWnd;
+}
+
 class XCursorThemeModel;
 
-#include "ui_selectwnd.h"
-class LXQT_API SelectWnd : public QWidget, private Ui_SelectWnd
+class LXQT_API SelectWnd : public QWidget
 {
     Q_OBJECT
 
@@ -55,6 +59,7 @@ private:
     XCursorThemeModel *mModel;
     QPersistentModelIndex mAppliedIndex;
     LXQt::Settings* mSettings;
+    Ui::SelectWnd *ui;
 };
 
 #endif

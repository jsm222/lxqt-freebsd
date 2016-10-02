--- lxqt-admin-user/mainwindow.h.orig	2016-09-23 22:44:08 UTC
+++ lxqt-admin-user/mainwindow.h
@@ -20,7 +20,7 @@
 
 #ifndef MAINWINDOW_H
 #define MAINWINDOW_H
-
+#include <QtCore/QtGlobal>
 #include <QMainWindow>
 #include "ui_mainwindow.h"
 
@@ -57,7 +57,9 @@ private Q_SLOTS:
     void onChangePasswd();
     void reload();
     void onRowActivated(const QModelIndex& index);
-
+    #ifndef Q_OS_LINUX
+    void onTabChange(int index);
+    #endif
 private:
     Ui::MainWindow ui;
     UserManager* mUserManager;

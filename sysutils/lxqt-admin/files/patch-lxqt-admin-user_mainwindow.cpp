--- lxqt-admin-user/mainwindow.cpp.orig	2016-09-23 22:44:08 UTC
+++ lxqt-admin-user/mainwindow.cpp
@@ -39,7 +39,9 @@ MainWindow::MainWindow():
     connect(ui.actionProperties, SIGNAL(triggered(bool)), SLOT(onEditProperties()));
     connect(ui.actionChangePasswd, SIGNAL(triggered(bool)), SLOT(onChangePasswd()));
     connect(ui.actionRefresh, SIGNAL(triggered(bool)), SLOT(reload()));
-
+    #ifndef Q_OS_LINUX
+    connect(ui.tabWidget,SIGNAL(currentChanged(int)),SLOT(onTabChange(int)));
+    #endif
     connect(ui.userList, &QListWidget::activated, this, &MainWindow::onRowActivated);
     connect(ui.groupList, &QListWidget::activated, this, &MainWindow::onRowActivated);
 
@@ -75,7 +77,15 @@ void MainWindow::reloadUsers()
         }
     }
 }
-
+#ifndef Q_OS_LINUX
+void MainWindow::onTabChange(int index) {
+if(index==1) {
+    ui.actionChangePasswd->setEnabled(false);
+} else {
+    ui.actionChangePasswd->setEnabled(true);
+}
+}
+#endif
 void MainWindow::reloadGroups()
 {
     ui.groupList->clear();

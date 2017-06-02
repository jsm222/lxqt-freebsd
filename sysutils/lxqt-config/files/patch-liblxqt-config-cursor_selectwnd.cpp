--- liblxqt-config-cursor/selectwnd.cpp.orig	2017-06-02 17:24:51 UTC
+++ liblxqt-config-cursor/selectwnd.cpp
@@ -13,6 +13,7 @@
 #include <QDebug>
 
 #include "selectwnd.h"
+#include "ui_selectwnd.h"
 
 #include <QKeyEvent>
 #include <QMessageBox>
@@ -37,22 +38,24 @@
 
 #define HOME_ICON_DIR QDir::homePath() + "/.icons"
 
-SelectWnd::SelectWnd(LXQt::Settings* settings, QWidget *parent) : QWidget(parent), mSettings(settings)
+SelectWnd::SelectWnd(LXQt::Settings* settings, QWidget *parent)
+    : QWidget(parent),
+      mSettings(settings),
+      ui(new Ui::SelectWnd)
 {
-    setupUi(this);
-
-    warningLabel->hide();
+    ui->setupUi(this);
+    ui->warningLabel->hide();
 
     mModel = new XCursorThemeModel(this);
 
     int size = style()->pixelMetric(QStyle::PM_LargeIconSize);
-    lbThemes->setModel(mModel);
-    lbThemes->setItemDelegate(new ItemDelegate(this));
-    lbThemes->setIconSize(QSize(size, size));
-    lbThemes->setSelectionMode(QAbstractItemView::SingleSelection);
+    ui->lbThemes->setModel(mModel);
+    ui->lbThemes->setItemDelegate(new ItemDelegate(this));
+    ui->lbThemes->setIconSize(QSize(size, size));
+    ui->lbThemes->setSelectionMode(QAbstractItemView::SingleSelection);
 
     // Make sure we find out about selection changes
-    connect(lbThemes->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)),
+    connect(ui->lbThemes->selectionModel(), SIGNAL(currentChanged(const QModelIndex &, const QModelIndex &)),
             SLOT(currentChanged(const QModelIndex &, const QModelIndex &)));
     // display/hide warning label
     connect(mModel, SIGNAL(modelReset()),
@@ -62,15 +65,15 @@ SelectWnd::SelectWnd(LXQt::Settings* set
     connect(mModel, SIGNAL(rowsRemoved(const QModelIndex&, int, int)),
                     this, SLOT(handleWarning()));
 
-    connect(warningLabel, SIGNAL(showDirInfo()),
+    connect(ui->warningLabel, SIGNAL(showDirInfo()),
                     this, SLOT(showDirInfo()));
 
     // Disable the install button if we can't install new themes to ~/.icons,
     // or Xcursor isn't set up to look for cursor themes there
-    btInstall->setEnabled(mModel->searchPaths().contains(HOME_ICON_DIR) && iconsIsWritable());
+    ui->btInstall->setEnabled(mModel->searchPaths().contains(HOME_ICON_DIR) && iconsIsWritable());
     // TODO/FIXME: btInstall functionality
-    btInstall->hide();
-    btRemove->hide();
+    ui->btInstall->hide();
+    ui->btRemove->hide();
 
     //QTimer::singleShot(0, this, SLOT(setCurrent()));
 
@@ -80,11 +83,12 @@ SelectWnd::SelectWnd(LXQt::Settings* set
 
 SelectWnd::~SelectWnd()
 {
+    delete ui;
 }
 
 void SelectWnd::setCurrent()
 {
-    lbThemes->selectionModel()->clear();
+    ui->lbThemes->selectionModel()->clear();
 
     QString ct = getCurrentTheme();
     mAppliedIndex = mModel->defaultIndex();
@@ -97,9 +101,9 @@ void SelectWnd::setCurrent()
         const XCursorThemeData *theme = mModel->theme(mAppliedIndex);
         // Select the current theme
         selectRow(mAppliedIndex);
-        lbThemes->scrollTo(mAppliedIndex, QListView::PositionAtCenter);
+        ui->lbThemes->scrollTo(mAppliedIndex, QListView::PositionAtCenter);
         // Update the preview widget as well
-        if (theme) preview->setTheme(*theme);// else preview->clearTheme();
+        if (theme) ui->preview->setTheme(*theme);// else ui->preview->clearTheme();
     }
 }
 
@@ -123,8 +127,8 @@ void SelectWnd::selectRow(int row) const
     QModelIndex from = mModel->index(row, 0);
     QModelIndex to = mModel->index(row, mModel->columnCount()-1);
     QItemSelection selection(from, to);
-    lbThemes->selectionModel()->select(selection, QItemSelectionModel::Select);
-    lbThemes->selectionModel()->setCurrentIndex(mAppliedIndex, QItemSelectionModel::NoUpdate);
+    ui->lbThemes->selectionModel()->select(selection, QItemSelectionModel::Select);
+    ui->lbThemes->selectionModel()->setCurrentIndex(mAppliedIndex, QItemSelectionModel::NoUpdate);
 }
 
 void SelectWnd::currentChanged(const QModelIndex &current, const QModelIndex &previous)
@@ -133,16 +137,16 @@ void SelectWnd::currentChanged(const QMo
     if (current.isValid()) {
         const XCursorThemeData *theme = mModel->theme(current);
         if (theme) {
-            preview->setTheme(*theme);
-            btRemove->setEnabled(theme->isWritable());
+            ui->preview->setTheme(*theme);
+            ui->btRemove->setEnabled(theme->isWritable());
         } else {
-            preview->clearTheme();
+            ui->preview->clearTheme();
         }
 
         // directly apply the current settings
         applyCurrent();
     } else {
-        preview->clearTheme();
+        ui->preview->clearTheme();
     }
    //emit changed(mAppliedIndex != current);
 }
@@ -155,7 +159,7 @@ void SelectWnd::on_btInstall_clicked()
 void SelectWnd::applyCurrent()
 {
     //qDebug() << "'set' clicked";
-    const XCursorThemeData *theme = mModel->theme(lbThemes->currentIndex());
+    const XCursorThemeData *theme = mModel->theme(ui->lbThemes->currentIndex());
     if (!theme) return;
     applyTheme(*theme);
     fixXDefaults(theme->name());
@@ -200,7 +204,7 @@ void SelectWnd::applyCurrent()
 void SelectWnd::on_btRemove_clicked()
 {
     qDebug() << "'remove' clicked";
-    const XCursorThemeData *theme = mModel->theme(lbThemes->currentIndex());
+    const XCursorThemeData *theme = mModel->theme(ui->lbThemes->currentIndex());
     if (!theme) return;
     QString ct = getCurrentTheme();
     if (ct == theme->name())
@@ -210,20 +214,20 @@ void SelectWnd::on_btRemove_clicked()
         return;
     }
     QDir d(theme->path());
-    preview->clearTheme();
-    mModel->removeTheme(lbThemes->currentIndex());
+    ui->preview->clearTheme();
+    mModel->removeTheme(ui->lbThemes->currentIndex());
     removeXCursorTheme(d);
 }
 
 void SelectWnd::handleWarning()
 {
         bool empty = mModel->rowCount();
-        warningLabel->setVisible(!empty);
-        preview->setVisible(empty);
-        infoLabel->setVisible(empty);
+        ui->warningLabel->setVisible(!empty);
+        ui->preview->setVisible(empty);
+        ui->infoLabel->setVisible(empty);
 }
 
 void SelectWnd::showDirInfo()
 {
-        QToolTip::showText(mapToGlobal(warningLabel->buttonPos()), mModel->searchPaths().join("\n"));
+        QToolTip::showText(mapToGlobal(ui->warningLabel->buttonPos()), mModel->searchPaths().join("\n"));
 }

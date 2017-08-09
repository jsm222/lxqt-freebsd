--- plugin-mainmenu/lxqtmainmenu.cpp.orig	2017-01-01 22:27:14 UTC
+++ plugin-mainmenu/lxqtmainmenu.cpp
@@ -470,19 +470,21 @@ bool LXQtMainMenu::eventFilter(QObject *
                 mMenu->hide(); // close the app menu
                 return true;
             }
-            else // go to the menu item starts with the pressed key
+            else // go to the menu item which starts with the pressed key if there is an active action.
             {
                 QString key = keyEvent->text();
                 if(key.isEmpty())
                     return false;
                 QAction* action = menu->activeAction();
-                QList<QAction*> actions = menu->actions();
-                QList<QAction*>::iterator it = qFind(actions.begin(), actions.end(), action);
-                it = std::find_if(it + 1, actions.end(), MatchAction(key));
-                if(it == actions.end())
-                    it = std::find_if(actions.begin(), it, MatchAction(key));
-                if(it != actions.end())
-                    menu->setActiveAction(*it);
+                if(action !=0) {
+                    QList<QAction*> actions = menu->actions();
+                    QList<QAction*>::iterator it = qFind(actions.begin(), actions.end(), action);
+                    it = std::find_if(it + 1, actions.end(), MatchAction(key));
+                    if(it == actions.end())
+                        it = std::find_if(actions.begin(), it, MatchAction(key));
+                    if(it != actions.end())
+                        menu->setActiveAction(*it);
+                }
             }
         }
 

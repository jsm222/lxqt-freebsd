--- lxqt-admin-user/usermanager.cpp.orig	2016-09-23 22:44:08 UTC
+++ lxqt-admin-user/usermanager.cpp
@@ -226,8 +226,13 @@ bool UserManager::addUser(UserInfo* user
     if(!user || user->name().isEmpty())
         return false;
     QStringList command;
+    #ifdef Q_OS_LINUX
     command << QStringLiteral("useradd");
-    if(user->uid() != 0) {
+    #else
+    command << QStringLiteral("pw");
+    command << QStringLiteral("useradd");
+    #endif
+     if(user->uid() != 0) {
         command << QStringLiteral("-u") << QString::number(user->uid());
     }
     if(!user->homeDir().isEmpty()) {
@@ -246,7 +251,11 @@ bool UserManager::addUser(UserInfo* user
     if(!user->groups().isEmpty()) {  // set group membership
         command << QStringLiteral("-G") << user->groups().join(',');
     }
+    #ifdef Q_OS_LINUX
     command << user->name();
+    #else
+    command << QStringLiteral("-n" ) << user->name();
+    #endif
     return pkexec(command);
 }
 
@@ -255,7 +264,12 @@ bool UserManager::modifyUser(UserInfo* u
         return false;
 
     QStringList command;
+    #ifdef Q_OS_LINUX
     command << QStringLiteral("usermod");
+    #else
+    command << QStringLiteral("pw");
+    command << QStringLiteral("usermod");
+    #endif
     if(newSettings->uid() != user->uid())
         command << QStringLiteral("-u") << QString::number(newSettings->uid());
 
@@ -278,8 +292,12 @@ bool UserManager::modifyUser(UserInfo* u
     if(newSettings->groups() != user->groups()) {  // change group membership
         command << QStringLiteral("-G") << newSettings->groups().join(',');
     }
-
+    #ifdef Q_OS_LINUX
+    command << user->name();
+    #else
+    command << QStringLiteral("-n");
     command << user->name();
+    #endif
     return pkexec(command);
 }
 
@@ -288,7 +306,12 @@ bool UserManager::deleteUser(UserInfo* u
         return false;
 
     QStringList command;
-    command << QStringLiteral("userdel");
+#ifdef Q_OS_LINUX
+command << QStringLiteral("userdel");
+#else
+command << QStringLiteral("pw");
+command << QStringLiteral("userdel");
+#endif
     command << user->name();
     return pkexec(command);
 }
@@ -320,7 +343,12 @@ bool UserManager::addGroup(GroupInfo* gr
         return false;
 
     QStringList command;
+    #ifdef Q_OS_LINUX
     command << QStringLiteral("groupadd");
+    #else
+    command << QStringLiteral("pw");
+    command << QStringLiteral("groupadd");
+    #endif
     if(group->gid() != 0) {
         command << QStringLiteral("-g") << QString::number(group->gid());
     }
@@ -332,7 +360,12 @@ bool UserManager::modifyGroup(GroupInfo*
     if(!group || group->name().isEmpty() || !newSettings)
         return false;
     QStringList command;
+    #ifdef Q_OS_LINUX
+    command << QStringLiteral("groupmod");
+    #else
+    command << QStringLiteral("pw");
     command << QStringLiteral("groupmod");
+    #endif
     if(newSettings->gid() != group->gid())
         command << QStringLiteral("-g") << QString::number(newSettings->gid());
     if(newSettings->name() != group->name())
@@ -340,13 +373,21 @@ bool UserManager::modifyGroup(GroupInfo*
     command << group->name();
     if(!pkexec(command))
         return false;
-
+    //TODO This yields a sudo prompt twice.. (jsm222)
     // if group members are changed, use gpasswd to reset members
     if(newSettings->members() != group->members()) {
         command.clear();
+        #ifdef Q_OS_LINUX
         command << QStringLiteral("gpasswd");
+        #else
+        command << QStringLiteral("pw");
+        command << QStringLiteral("groupmod");
+        #endif
         command << QStringLiteral("-M");  // Set the list of group members.
         command << newSettings->members().join(',');
+        #ifndef Q_OS_LINUX
+        command << QStringLiteral("-n");
+        #endif
         command << group->name();
         return pkexec(command);
     }
@@ -357,7 +398,12 @@ bool UserManager::deleteGroup(GroupInfo*
     if(!group || group->name().isEmpty())
         return false;
     QStringList command;
+    #ifdef Q_OS_LINUX
+    command << QStringLiteral("groupdel");
+    #else
+    command << QStringLiteral("pw");
     command << QStringLiteral("groupdel");
+    #endif
     command << group->name();
     return pkexec(command);
 }

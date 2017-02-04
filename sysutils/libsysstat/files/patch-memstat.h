--- memstat.h.orig	2016-12-10 23:50:29 UTC
+++ memstat.h
@@ -35,6 +35,12 @@
 
 namespace SysStat {
 
+#if defined(HAVE_SYSCTL_H) && defined(HAVE_KVM_H)
+    int SwapDevices();
+    qulonglong MemGetByBytes(const QString property);
+    qulonglong MemGetByPages(const QString property);
+#endif
+
 class MemStatPrivate;
 
 class SYSSTATSHARED_EXPORT MemStat : public BaseStat

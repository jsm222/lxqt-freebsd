# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-qtplugin
PORTVERSION=	0.13.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	LXQt system integration plugin for Qt

LICENSE=	LGPL21+

LIB_DEPENDS=	libdbusmenu-qt5.so:devel/libdbusmenu-qt@qt5

USES=	cmake:outsource compiler:c++11-lib kde:5 lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui svg widgets \
	x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools qtxdg libfmqt
USE_LDCONFIG=	yes

PLIST_FILES=	%%QT_PLUGINDIR%%/platformthemes/libqtlxqt.so

.include <bsd.port.mk>

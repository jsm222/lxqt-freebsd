# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-qtplugin
PORTVERSION=	0.10.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt system integration plugin for Qt

LIB_DEPENDS=	libdbusmenu-qt5.so:${PORTSDIR}/devel/libdbusmenu-qt5

USES=	cmake:outsource compiler:c++11-lib lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build dbus linguisttools widgets
USE_LXQT=	lxqt
USE_LDCONFIG=	yes

PLIST_FILES=	%%QT_PLUGINDIR%%/platformthemes/libqtlxqt.so

.include <bsd.port.mk>

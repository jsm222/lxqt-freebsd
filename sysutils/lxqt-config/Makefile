# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-config
PORTVERSION=	0.11.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt system settings center

LICENSE=	GPLv2 LGPL21+
LICENSE_COMB=	multi

USES=	cmake:outsource compiler:c++11-lib kde:5 localbase lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build concurrent core dbus \
	gui svg widgets x11extras xml
USE_KDE=	libkscreen windowsystem
USE_LXQT=	lxqt
USE_XORG=	ice sm x11 xcb xcursor xext xfixes xrandr

CMAKE_ARGS+=	-DPULL_TRANSLATIONS:BOOL=OFF

.include <bsd.port.mk>

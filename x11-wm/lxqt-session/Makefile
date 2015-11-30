# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-session
PORTVERSION=	0.10.0
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Session manager component for LXQt

USES=	cmake:outsource compiler:c++11-lib gettext kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build dbus linguisttools \
	widgets x11extras
USE_KDE=	windowsystem
USE_LXQT=	lxqt
USE_XORG=	x11 xcb

CMAKE_ARGS+=	-DLIBUDEV_MONITOR:BOOL=OFF

.include <bsd.port.mk>

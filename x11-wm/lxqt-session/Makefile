# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-session
PORTVERSION=	0.13.0
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Session manager component for LXQt

LICENSE=	LGPL21+

BUILD_DEPENDS=	xdg-user-dirs-update:devel/xdg-user-dirs

USES=	cmake:outsource compiler:c++11-lib kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui linguisttools \
	svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt qtxdg
USE_XORG=	x11 ice sm xcb xext

CMAKE_ARGS+=	-DWITH_LIBUDEV:BOOL=OFF

.include <bsd.port.mk>

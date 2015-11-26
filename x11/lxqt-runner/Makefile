# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-runner
PORTVERSION=	0.10.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt tool used to launch programs quickly

LIB_DEPENDS=	libmenu-cache.so:${PORTSDIR}/x11/menu-cache

USES=	cmake:outsource gettext kde:5 lxqt pkgconfig tar:xz
USE_QT5=	linguisttools script widgets xml
USE_KDE=	windowsystem
USE_LXQT=	globalkeys

CMAKE_ARGS=	-DRUNNER_VBOX:BOOL=OFF

.include <bsd.port.mk>

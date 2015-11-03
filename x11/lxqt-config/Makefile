# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-config
PORTVERSION=	0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/%SUBDIR%/
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt system settings center

LICENSE=	LGPL21

USES=	cmake pkgconfig gettext tar:xz
USE_QT5=	concurrent dbus linguisttools widgets x11extras xml
USE_LXQT=	lxqt
USE_XORG=	x11 xcursor xrandr

.include <bsd.port.mk>

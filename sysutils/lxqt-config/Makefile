# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-config
PORTVERSION=	0.10.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt system settings center

USES=	cmake:outsource gettext kde:5 lxqt pkgconfig tar:xz
USE_QT5=	concurrent dbus linguisttools svg widgets x11extras xml
USE_KDE=	libkscreen
USE_LXQT=	lxqt
USE_XORG=	x11 xcursor xrandr

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	liblxqt
PORTVERSION=	0.9.0
CATEGORIES=	x11
MASTER_SITES=	http://downloads.lxqt.org/%SUBDIR%/
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Shared library for LXQt applications

LICENSE=	LGPL21

LIB_DEPENDS=	libKF5WindowSystem.so:${PORTSDIR}/x11/kwindowsystem

USES=	cmake pkgconfig gettext tar:xz
USE_QT5=	dbus linguisttools widgets x11extras xml
USE_LXQT=	qtxdg

.include <bsd.port.mk>

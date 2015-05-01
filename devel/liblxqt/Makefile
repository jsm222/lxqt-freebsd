# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	liblxqt
PORTVERSION=	0.9.0
CATEGORIES=	devel
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Shared library for LXQt applications

LIB_DEPENDS=	libKF5WindowSystem.so:${PORTSDIR}/x11/kwindowsystem

USES=	cmake pkgconfig gettext lxqt tar:xz
USE_QT5=	dbus linguisttools widgets x11extras xml
USE_LXQT=	qtxdg

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	liblxqt
PORTVERSION=	0.10.0
CATEGORIES=	devel
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Shared library for LXQt applications

USES=	cmake:outsource compiler:c++11-lib gettext kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build dbus linguisttools \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	qtxdg

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	qterminal
PORTVERSION=	0.6.0
CATEGORIES=	x11
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Lightweight Qt terminal emulator

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

USES=	cmake:outsource gettext lxqt pkgconfig
USE_QT5=	buildtools_build qmake_build linguisttools widgets
USE_LXQT=	qterm
USE_XORG=	x11

LDFLAGS+=	-L${LOCALBASE}/lib

CMAKE_ARGS=	-DUSE_SYSTEM_QXT:BOOL=OFF \
	-DUSE_QT5:BOOL=ON

.include <bsd.port.mk>

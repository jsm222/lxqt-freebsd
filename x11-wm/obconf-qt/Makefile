# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	obconf-qt
PORTVERSION=	0.9.0
CATEGORIES=	x11-wm
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt port of preferences manager for the Openbox

LICENSE=	GPLv2

LIB_DEPENDS=	libobt.so:${PORTSDIR}/x11-wm/openbox

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

USES=	cmake:outsource pkgconfig
USE_QT5=	buildtools_build qmake_build linguisttools widgets \
	x11extras
USE_GNOME=	glib20

CMAKE_ARGS=	-DUSE_QT5:BOOL=ON

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libqtxdg
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	http://downloads.lxqt.org/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt implementation of freedesktop.org xdg specs

LICENSE=	LGPL21

USES=	cmake pkgconfig tar:xz
USE_QT5=	core widgets xml

# LXQt is build on top of Qt5
CONFIGURE_ARGS=-DUSE_QT5=ON -DUSE_QT4=OFF

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libqtxdg
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt implementation of freedesktop.org xdg specs


USES=	cmake pkgconfig lxqt tar:xz
USE_QT5=	core widgets xml

# LXQt is build on top of Qt5
CONFIGURE_ARGS=-DUSE_QT5:BOOL=ON -DUSE_QT4:BOOL=OFF

PLIST_SUB+=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>

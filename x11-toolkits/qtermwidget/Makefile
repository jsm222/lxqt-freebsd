# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	qtermwidget
PORTVERSION=	0.6.0
CATEGORIES=	x11-toolkits
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Terminal widget based on Qt

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

USES=	cmake:outsource pkgconfig
USE_QT5=	core xml widgets

CMAKE_ARGS=	-DBUILD_DESIGNER_PLUGIN:BOOL=OFF \
	-DUSE_QT5:BOOL=ON

post-patch:
	${REINPLACE_CMD} -e '/define HAVE_LOGIN/d' \
		${WRKSRC}/lib/kpty.cpp

.include <bsd.port.mk>

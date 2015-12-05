# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	mdiedit
PORTVERSION=	0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Simple text editor written with Qt toolkits

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	selairi

USES=	cmake:outsource desktop-file-utils pkgconfig
USE_QT5=	buildtools_build widgets x11extras
INSTALLS_ICONS=	yes

WRKSRC=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/mdiedit

CMAKE_ARGS+=	-DUSE_QT4:BOOL=OFF \
	-DUSE_QT5:BOOL=ON

.include <bsd.port.mk>

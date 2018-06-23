# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	featherpad
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	V
CATEGORIES=	editors

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Lightweight Qt5 plain-text editor

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	tsujan
GH_PROJECT=	FeatherPad

USES=	compiler:c++11-lang desktop-file-utils pkgconfig qmake:outsource
USE_QT5=	buildtools_build core gui printsupport network \
	svg widgets x11extras
USE_XORG=	x11
USE_GL=	gl

.include <bsd.port.mk>

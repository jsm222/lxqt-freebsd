# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	qlipper
PORTVERSION=	5.0.0
CATEGORIES=	deskutils
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Lightweight clipboard history applet

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	debian-lxqt
GH_TAGNAME=	8db4f06

USES=	cmake:outsource compiler:c++11-lang gettext
USE_QT5=	buildtools_build qmake_build core gui linguisttools \
	network widgets
USE_XORG=	x11
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

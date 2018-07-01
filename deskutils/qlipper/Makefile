# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	qlipper
PORTVERSION=	5.1.1
CATEGORIES=	deskutils

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Lightweight clipboard history applet

LICENSE=	GPLv2

USES=	cmake:outsource compiler:c++11-lang gettext qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	pvanek
GH_TAGNAME=	ae468df

USE_QT=	buildtools_build qmake_build core gui linguisttools \
	network widgets
USE_XORG=	x11
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

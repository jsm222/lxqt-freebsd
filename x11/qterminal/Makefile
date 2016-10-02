# Created by: Jason Bacon <bacon4000@gmail.com>
# $FreeBSD$

PORTNAME=	qterminal
PORTVERSION=	0.7.0
CATEGORIES=	x11
MASTER_SITES=	https://downloads.lxqt.org/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	bacon4000@gmail.com
COMMENT=	Lightweight Qt-based terminal emulator

LICENSE=	GPLv2

LIB_DEPENDS=	libqtermwidget5.so:x11-toolkits/qtermwidget
RUN_DEPENDS=	liberation-fonts-ttf>=2.00:x11-fonts/liberation-fonts-ttf

USES=		cmake:outsource compiler:c++11-lang localbase lxqt \
		pkgconfig tar:xz
USE_QT5+=	buildtools_build core gui qmake_build widgets x11extras
USE_XORG+=	x11
USE_LXQT=	lxqt

CMAKE_ARGS+=	-DUSE_SYSTEM_QXT:BOOL=OFF

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

LDFLAGS+=	-lulog

.include <bsd.port.mk>

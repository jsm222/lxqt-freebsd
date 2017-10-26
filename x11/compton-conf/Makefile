# Created by: Jesper Schmitz Mouridsen
# $FreeBSD$

PORTNAME=	compton-conf
PORTVERSION=	0.3.0
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Controls compton settings 

LICENSE=	LGPL21+

LIB_DEPENDS=	libconfig.so:devel/libconfig
RUN_DEPENDS=	compton:x11-wm/compton

USES=	cmake:outsource compiler:c++11-lib localbase:ldflags lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui linguisttools \
	widgets
USE_LXQT=	buildtools
SUB_FILES=	pkg-message

.include <bsd.port.mk>

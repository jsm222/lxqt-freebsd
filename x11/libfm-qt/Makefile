# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-qt
PORTVERSION=	0.11.0
CATEGORIES=	x11
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Qt port of libfm

LIB_DEPENDS=	libfm.so:${PORTSDIR}/x11/libfm

USES=	cmake:outsource compiler:c++11-lib gettext lxqt pkgconfig \
	tar:xz
USE_QT5=	buildtools_build qmake_build linguisttools widgets \
	x11extras
USE_GNOME=	glib20
USE_XORG=	xcb

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/include/libfm-qt/translations

.include <bsd.port.mk>

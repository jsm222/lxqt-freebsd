# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pcmanfm-qt
PORTVERSION=	0.10.0
CATEGORIES=	x11-fm
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt file manager

LICENSE=	GPLv2

USES=	cmake:outsource desktop-file-utils gettext lxqt pkgconfig tar:xz
USE_GNOME=	glib20
USE_QT5=	buildtools_build qmake_build dbus linguisttools widgets \
	x11extras
USE_LXQT=	libfm
USE_XORG=	xcb

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/include/libfm-qt/translations

.include <bsd.port.mk>

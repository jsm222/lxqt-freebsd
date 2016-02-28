# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pcmanfm-qt
PORTVERSION=	0.10.1
CATEGORIES=	x11-fm
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt file manager

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

USES=	cmake:outsource desktop-file-utils gettext lxqt pkgconfig tar:xz
USE_GNOME=	glib20
USE_QT5=	buildtools_build qmake_build dbus linguisttools widgets \
	x11extras
USE_LXQT=	libfmqt
USE_XORG=	xcb

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>

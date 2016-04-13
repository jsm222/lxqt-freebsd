# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pcmanfm-qt
PORTVERSION=	0.11.0
CATEGORIES=	x11-fm
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt file manager

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	lxde

USES=	cmake:outsource compiler:c++11-lib desktop-file-utils gettext \
	localbase lxqt pkgconfig
USE_GNOME=	glib20
USE_QT5=	buildtools_build qmake_build dbus linguisttools widgets \
	x11extras
USE_LXQT=	libfmqt
USE_XORG=	xcb

.include <bsd.port.mk>

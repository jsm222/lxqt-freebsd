# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-runner
PORTVERSION=	0.11.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt tool used to launch programs quickly

LICENSE=	LGPL21+

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
	libmuparser.so:math/muparser

USES=	cmake:outsource compiler:c++11-lib gettext-runtime kde:5 \
	localbase lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui script svg \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	globalkeys qtxdg

CMAKE_ARGS=	-DRUNNER_VBOX:BOOL=OFF

PLIST_FILES=	bin/lxqt-runner

.include <bsd.port.mk>

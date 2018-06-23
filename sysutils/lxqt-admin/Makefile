# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-admin
PORTVERSION=	0.13.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	System administration tool for the LXQt desktop

LICENSE=	LGPL21+

USES=	cmake:outsource kde:5 localbase lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui svg \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	buildtools lxqt
SUB_FILES=	pkg-message

.include <bsd.port.mk>

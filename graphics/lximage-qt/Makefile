# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lximage-qt
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Image viewer and screenshot tool

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif

USES=	desktop-file-utils cmake:outsource lxqt pkgconfig tar:xz
USE_GNOME=	glib20
USE_QT5=	buildtools_build qmake_build dbus linguisttools \
	printsupport widgets x11extras
USE_LXQT=	libfmqt5
USE_XORG=	x11 xfixes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

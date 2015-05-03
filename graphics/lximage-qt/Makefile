# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lximage-qt
PORTVERSION=	0.4.0
CATEGORIES=	graphics
MASTER_SITES=	LXQT/${PORTNAME}/${PORTVERSION}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Image viewer and screenshot tool

LICENSE=	GPLv2

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif

USES=	cmake pkgconfig desktop-file-utils lxqt tar:xz
USE_GNOME=	glib20
USE_QT5=	dbus linguisttools printsupport widgets x11extras
USE_LXQT=	libfmqt5
USE_XORG=	x11 xfixes
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-admin
PORTVERSION=	0.10.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	System administration tool for the LXQt desktop

LIB_DEPENDS=	liboobs-1.so:${PORTSDIR}/devel/liboobs

USES=	cmake:outsource gettext kde:5 lxqt pkgconfig tar:xz
USE_QT5=	widgets
USE_KDE=	windowsystem
USE_GNOME=	glib20
USE_LXQT=	lxqt

.include <bsd.port.mk>

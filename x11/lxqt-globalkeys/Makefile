# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-globalkeys
PORTVERSION=	0.11.0
CATEGORIES=	x11
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Global keyboard shortcuts registration

LICENSE=	LGPL21+

USES=	cmake:outsource kde:5 lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui svg \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	lxqt
USE_XORG=	ice sm x11 xext

CMAKE_ARGS+=	-DPULL_TRANSLATIONS:BOOL=OFF

.include <bsd.port.mk>

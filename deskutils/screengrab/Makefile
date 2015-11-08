# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	screengrab
PORTVERSION=	1.95
CATEGORIES=	deskutils
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Take screenshots using Qt framework

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	QtDesktop

USES=	cmake:outsource gettext kde:5 lxqt pkgconfig
USE_QT5=	dbus linguisttools network widgets x11extras
USE_KDE=	windowsystem
USE_LXQT=	qtxdg
USE_XORG=	x11 xcb
INSTALLS_ICONS=	yes

.include <bsd.port.mk>

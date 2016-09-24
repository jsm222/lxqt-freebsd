# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-notificationd
PORTVERSION=	0.11.0
CATEGORIES=	deskutils
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt notification daemon

LICENSE=	LGPL21+

USES=	cmake:outsource compiler:c++11-lib gettext kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build dbus core gui \
	linguisttools svg widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	lxqt

.include <bsd.port.mk>

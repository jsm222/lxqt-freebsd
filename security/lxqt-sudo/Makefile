# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-sudo
PORTVERSION=	0.13.0
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	jesper@schmitz.computer
COMMENT=	GUI frontend to su/sudo for LXQt desktop

LICENSE=	LGPL21+

SUB_FILES=	pkg-message

USES=	cmake:outsource compiler:c++11-lib gettext kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui svg widgets \
	x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	buildtools lxqt

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-openssh-askpass
PORTVERSION=	0.11.0
CATEGORIES=	security
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt GUI dialog for OpenSSH authentication

LICENSE=	LGPL21+

USES=	cmake:outsource gettext kde:5 lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui svg \
	widgets x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	lxqt

PLIST_FILES=	bin/lxqt-openssh-askpass

.include <bsd.port.mk>

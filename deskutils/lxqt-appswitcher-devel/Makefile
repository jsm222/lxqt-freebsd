# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-appswitcher
PORTVERSION=	20151126
CATEGORIES=	deskutils
#MASTER_SITES=	LOCAL/olivierd
PKGNAMESUFFIX=	-devel
DIST_SUBDIR=	lxqt

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Applications switcher for the LXQt desktop

USES=	cmake:outsource compiler:c++11-lang lxqt kde:5 pkgconfig tar:bz2
USE_QT5=	core widgets
USE_KDE=	windowsystem
USE_LXQT=	globalkeys

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/autostart
	${INSTALL_DATA} ${FILESDIR}/lxqt-appswitcher.desktop \
		${STAGEDIR}${PREFIX}/etc/xdg/autostart

.include <bsd.port.mk>

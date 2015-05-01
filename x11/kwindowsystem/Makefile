# Created by: Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	kwindowsystem
PORTVERSION=	5.8.0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/frameworks/${KDE5_BRANCH}
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Access to the windowing system

LICENSE=	LGPL21

BUILD_DEPENDS=	extra-cmake-modules>=1.8:${PORTSDIR}/devel/extra-cmake-modules

KDE5_BRANCH?=	5.8

USES=	cmake pkgconfig gettext tar:xz
USE_QT5=	core gui linguisttools testlib widgets x11extras
USE_XORG=	ice x11 xcb xfixes xrender

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-policykit
PORTVERSION=	0.9.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	PolicyKit authentication agent

LIB_DEPENDS=	libpolkit-qt5-agent-1.so:${PORTSDIR}/sysutils/polkit-qt5

USES=	cmake pkgconfig gettext lxqt tar:xz
USE_QT5=	linguisttools widgets
USE_LXQT=	lxqt

.include <bsd.port.mk>

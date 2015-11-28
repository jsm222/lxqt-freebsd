# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt
PORTVERSION=	0.10.0
CATEGORIES=	x11-wm

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	The "meta-port" for the LXQt Desktop

RUN_DEPENDS=	startlxqt:${PORTSDIR}/misc/lxqt-common \
	lxqt-about:${PORTSDIR}/x11/lxqt-about \
	lxqt-admin-user:${PORTSDIR}/sysutils/lxqt-admin \
	lxqt-config:${PORTSDIR}/sysutils/lxqt-config \
	lxqt-qtplugin>=0.10:${PORTSDIR}/sysutils/lxqt-qtplugin \
	qterminal:${PORTSDIR}/x11/qterminal \
	obconf-qt:${PORTSDIR}/x11-wm/obconf-qt \
	lximage-qt:${PORTSDIR}/graphics/lximage-qt

USES=	metaport

OPTIONS_DEFINE=	SSH
OPTIONS_DEFAULT=	SSH SCREENGRAB
SSH_RUN_DEPENDS=	lxqt-openssh-askpass:${PORTSDIR}/security/lxqt-openssh-askpass
SCREENGRAB_RUN_DEPENDS=	screengrab:${PORTSDIR}/deskutils/screengrab
SCREENGRAB_DESC=	Screenshot utility

do-install:	# empty

.include <bsd.port.mk>

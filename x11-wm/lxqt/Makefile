# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt
PORTVERSION=	0.10.0
CATEGORIES=	x11-wm

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	The "meta-port" for the LXQt Desktop

RUN_DEPENDS=	startlxqt:misc/lxqt-common \
	lxqt-about:x11/lxqt-about \
	lxqt-admin-user:sysutils/lxqt-admin \
	lxqt-config:sysutils/lxqt-config \
	lxqt-qtplugin>=0.10:sysutils/lxqt-qtplugin \
	qterminal:x11/qterminal \
	obconf-qt:x11-wm/obconf-qt \
	lximage-qt:graphics/lximage-qt

USES=	metaport

OPTIONS_DEFINE=	SSH SCREENGRAB
OPTIONS_DEFAULT=	SSH
SSH_RUN_DEPENDS=	lxqt-openssh-askpass:security/lxqt-openssh-askpass
SCREENGRAB_RUN_DEPENDS=	screengrab:deskutils/screengrab
SCREENGRAB_DESC=	Screenshot utility

do-install:	# empty

.include <bsd.port.mk>

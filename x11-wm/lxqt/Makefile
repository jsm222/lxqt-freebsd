# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt
PORTVERSION=	0.11.0
CATEGORIES=	x11-wm

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	The "meta-port" for the LXQt Desktop

LICENSE=	LGPL21+

RUN_DEPENDS=	startlxqt:misc/lxqt-common \
	lxqt-about:x11/lxqt-about \
	lxqt-admin-user:sysutils/lxqt-admin \
	lxqt-config:sysutils/lxqt-config \
	lxqt-qtplugin>=0.11:sysutils/lxqt-qtplugin \
	qterminal:x11/qterminal \
	obconf-qt:x11-wm/obconf-qt \
	lximage-qt:graphics/lximage-qt

USES=	metaport

OPTIONS_DEFINE=	SSH SUDO
OPTIONS_DEFAULT=	SSH
SSH_RUN_DEPENDS=	lxqt-openssh-askpass:security/lxqt-openssh-askpass
SUDO_RUN_DEPENDS=	lxqt-sudo:security/lxqt-sudo
SUDO_DESC=	GUI frontend (Qt5) to sudo/su

.include <bsd.port.mk>

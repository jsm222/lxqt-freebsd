# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt
PORTVERSION=	0.13.0
CATEGORIES=	x11-wm

MAINTAINER=	jesper@schmitz.computer

LICENSE=	LGPL21+

COMMENT=	meta-port for the LXQt Desktop

RUN_DEPENDS=	startlxqt:x11-wm/lxqt-session \
	lxqt-about:x11/lxqt-about \
	lxqt-admin-user:sysutils/lxqt-admin \
	lxqt-config:sysutils/lxqt-config \
	lxqt-qtplugin>=0.11:sysutils/lxqt-qtplugin \
	qterminal:x11/qterminal \
	obconf-qt:x11-wm/obconf-qt \
	lximage-qt:graphics/lximage-qt \
	lxqt-panel:x11-wm/lxqt-panel \
	lxqt-runner:x11/lxqt-runner \
	${PREFIX}/share/lxqt/themes/frost/lxqt-panel.qss:x11-themes/lxqt-themes \
	pcmanfm-qt:x11-fm/pcmanfm-qt \
	lxqt-notificationd:deskutils/lxqt-notificationd \
	lxqt-panel:x11-wm/lxqt-panel \
	lxqt-runner:x11/lxqt-runner \
	lxqt-policykit-agent:sysutils/lxqt-policykit \
	lxqt-session:x11-wm/lxqt-session \
	qlipper:deskutils/qlipper \
	openbox:x11-wm/openbox

USES=	metaport

OPTIONS_DEFINE=	EDITOR SSH SUDO
OPTIONS_DEFAULT=	SUDO
EDITOR_RUN_DEPENDS=	featherpad:editors/featherpad
EDITOR_DESC=	Install plain-text editor
SSH_RUN_DEPENDS=	lxqt-openssh-askpass:security/lxqt-openssh-askpass
SUDO_RUN_DEPENDS=	lxqt-sudo:security/lxqt-sudo
SUDO_DESC=	GUI frontend (Qt5) to sudo/su

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-common
PORTVERSION=	0.10.0
CATEGORIES=	misc
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt common files

RUN_DEPENDS=	xscreensaver:${PORTSDIR}/x11/xscreensaver \
	pcmanfm-qt:${PORTSDIR}/x11-fm/pcmanfm-qt \
	lxqt-notificationd:${PORTSDIR}/deskutils/lxqt-notificationd \
	lxqt-panel:${PORTSDIR}/x11-wm/lxqt-panel \
	lxqt-runner:${PORTSDIR}/x11/lxqt-runner \
	lxqt-policykit-agent:${PORTSDIR}/sysutils/lxqt-policykit \
	lxqt-session:${PORTSDIR}/x11-wm/lxqt-session \
	qlipper:${PORTSDIR}/deskutils/qlipper \
	openbox:${PORTSDIR}/x11-wm/openbox
	

USES=	cmake:outsource kde:4 lxqt tar:xz
USE_KDE=	oxygen-icons
USE_LXQT=	globalkeys

post-extract:
.for s in lxqt.conf session.conf
	${MV} ${WRKSRC}/config/${s} ${WRKSRC}/config/${s}.sample
.endfor

.include <bsd.port.mk>

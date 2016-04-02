# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-common
PORTVERSION=	0.10.0
CATEGORIES=	misc
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt common files

RUN_DEPENDS=	xscreensaver:x11/xscreensaver \
	pcmanfm-qt:x11-fm/pcmanfm-qt \
	lxqt-notificationd:deskutils/lxqt-notificationd \
	lxqt-panel:x11-wm/lxqt-panel \
	lxqt-runner:x11/lxqt-runner \
	lxqt-policykit-agent:sysutils/lxqt-policykit \
	lxqt-session:x11-wm/lxqt-session \
	qlipper:deskutils/qlipper \
	openbox:x11-wm/openbox
	

USES=	cmake:outsource kde:5 lxqt tar:xz
USE_KDE=	oxygen-icons5
USE_QT5=	buildtools_build qmake_build
USE_LXQT=	globalkeys

post-extract:
.for s in lxqt.conf session.conf
	${MV} ${WRKSRC}/config/${s} ${WRKSRC}/config/${s}.sample
.endfor

.include <bsd.port.mk>

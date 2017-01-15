# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-common
PORTVERSION=	0.11.2
CATEGORIES=	misc
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	LXQt common files

LICENSE=	LGPL21+

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
USE_LXQT=	buildtools globalkeys

OPTIONS_DEFINE=	COMPTON
COMPTON_RUN_DEPENDS=	compton-conf:x11/compton-conf
COMPTON_DESC=	Support of GUI configuration tool of Compton
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-extract:
.for s in lxqt.conf session.conf
	${MV} ${WRKSRC}/config/${s} ${WRKSRC}/config/${s}.sample
.endfor

post-patch:
.if ${PORT_OPTIONS:MCOMPTON}
	${REINPLACE_CMD} -e 's|"lxqt-compton|#"lxqt-compton|' \
		${WRKSRC}/autostart/CMakeLists.txt
.endif

.include <bsd.port.mk>

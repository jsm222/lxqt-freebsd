# Created by: Tobias Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	kwin
PORTVERSION=	${KDE_PLASMA_VERSION}
PORTREVISION=	3
CATEGORIES=	x11-wm kde # kde-plasma

COMMENT=	Plasma5 window manager

LIB_DEPENDS=	libepoxy.so:${PORTSDIR}/graphics/libepoxy \
		libXcursor.so.1:${PORTSDIR}/x11/libXcursor \
		libxcb-cursor.so:${PORTSDIR}/x11/xcb-util-cursor

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:${PORTSDIR}/multimedia/v4l_compat

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 pkgconfig tar:xz
USE_GL=		egl
USE_QT5=	buildtools_build concurrent core dbus designer gui \
		multimedia network qmake_build qml quick script \
		testlib uitools widgets x11extras
USE_KDE=	activities activities completion config configwidgets \
		coreaddons crash decoration doctools doctools globalaccel i18n \
		iconthemes idletime init kcmutils kdeclarative kio kpackage \
		kscreenlocker newstuff notifications plasma-framework service \
		widgetsaddons windowsystem xmlgui
KDE_DIST=	plasma

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	YES

.include <bsd.port.mk>

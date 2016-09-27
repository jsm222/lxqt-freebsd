# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-panel
PORTVERSION=	0.11.0
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Panel for the LXQt desktop

LICENSE=	LGPL21+

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
	libdbusmenu-qt5.so:devel/libdbusmenu-qt5 \
	libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	lxmenu-data>=0.1.2:x11/lxmenu-data

USES=	cmake:outsource compiler:c++11-lib gettext-runtime kde:5 localbase \
	lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui svg widgets \
	x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	lxqt globalkeys qtxdg
USE_XORG=	ice sm x11 xcb xcomposite xdamage xext xfixes xrender
USE_GNOME=	glib20

OPTIONS_DEFINE=	MOUNT PULSEAUDIO
OPTIONS_DEFAULT=	PULSEAUDIO
PULSEAUDIO_CMAKE_ON=	-DVOLUME_USE_ALSA:BOOL=OFF
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_OFF=	-DVOLUME_PLUGIN:BOOL=OFF
MOUNT_USE=	kde=solid
MOUNT_CMAKE_OFF=	-DMOUNT_PLUGIN:BOOL=OFF
MOUNT_DESC=	Mount removable devices support
OPTIONS_SUB=	yes

CMAKE_ARGS+=	-DCPULOAD_PLUGIN:BOOL=OFF \
	-DSENSORS_PLUGIN:BOOL=OFF \
	-DNETWORKMONITOR_PLUGIN:BOOL=OFF \
	-DSYSSTAT_PLUGIN:BOOL=OFF

.include <bsd.port.mk>

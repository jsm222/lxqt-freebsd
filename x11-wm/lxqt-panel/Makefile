# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-panel
PORTVERSION=	0.10.0
CATEGORIES=	x11-wm
MASTER_SITES=	LXQT

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Panel for the LXQt desktop

LIB_DEPENDS=	libmenu-cache.so:${PORTSDIR}/x11/menu-cache \
	libdbusmenu-qt5.so:${PORTSDIR}/devel/libdbusmenu-qt5 \
	libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon

USES=	cmake:outsource compiler:c++11-lib gettext kde:5 lxqt \
	pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build dbus linguisttools widgets \
	x11extras xml
USE_KDE=	windowsystem
USE_LXQT=	globalkeys
USE_XORG=	x11 xcb xcomposite xdamage xrender

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

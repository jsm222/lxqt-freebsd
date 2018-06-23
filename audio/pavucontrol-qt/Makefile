# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	pavucontrol-qt
PORTVERSION=	0.4.0
CATEGORIES=	audio
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jesper@schmitz.computer
COMMENT=	PulseAudio mixer in Qt

LICENSE=	GPLv2

BUILD_DEPENDS=	xdg-user-dirs-update:devel/xdg-user-dirs
LIB_DEPENDS=	libpulse.so:audio/pulseaudio
RUN_DEPENDS=	xdg-user-dir:devel/xdg-user-dirs

USES=	cmake:outsource compiler:c++0x gettext-runtime localbase:ldflags \
	lxqt pkgconfig tar:xz
USE_QT5=	buildtools_build qmake_build core dbus gui linguisttools \
	widgets
USE_LXQT=	buildtools
USE_GNOME=	glib20

PLIST_FILES=	bin/pavucontrol-qt \
	share/applications/pavucontrol-qt.desktop

.include <bsd.port.mk>

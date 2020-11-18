# Created by: Olivier Duchateau
# $FreeBSD: head/audio/pavucontrol-qt/Makefile 539706 2020-06-20 08:24:14Z jsm $

PORTNAME=	pavucontrol-qt
PORTVERSION=	0.16.0
CATEGORIES=	audio
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jsm@FreeBSD.org
COMMENT=	PulseAudio mixer in Qt

LICENSE=	GPLv2

LIB_DEPENDS=	libpulse.so:audio/pulseaudio

USES=	cmake compiler:c++14-lang gettext-runtime localbase:ldflags qt:5 \
	lxqt pkgconfig tar:xz gnome
USE_QT=	buildtools_build qmake_build core dbus gui linguisttools \
	widgets
USE_LXQT=	buildtools
USE_GNOME=	glib20

.include <bsd.port.mk>

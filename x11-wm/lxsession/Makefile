# Created by: chinsan
# $FreeBSD: head/x11-wm/lxsession/Makefile 357070 2014-06-08 19:51:27Z olgeni $

PORTNAME=	lxsession
PORTVERSION=	0.5.2
CATEGORIES=	x11-wm
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%20${PORTVERSION:R}.x/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	Session manager for LXDE

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
	libunique-1.0.so:${PORTSDIR}/x11-toolkits/unique \
	libpolkit-gobject-1.so:${PORTSDIR}/sysutils/polkit

USES=		gmake pkgconfig gettext-tools tar:xz
USE_GNOME=	glib20 gtk20 intltool intlhack
GNU_CONFIGURE=	yes
USE_XORG=	x11

CONFIGURE_ARGS=--enable-buildin-polkit \
	--enable-buildin-clipboard

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

.include <bsd.port.mk>

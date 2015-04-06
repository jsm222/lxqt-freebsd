# Created by: sahne
# $FreeBSD: head/misc/lxde-common/Makefile 351711 2014-04-21 20:27:38Z nemysis $

PORTNAME=	lxde-common
PORTVERSION=	0.99.0
CATEGORIES=	misc
MASTER_SITES=	SF/lxde/${PORTNAME}%20%28default%20config%29/${PORTNAME}%20${PORTVERSION:R}/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	LXDE Common files

LICENSE=	GPLv2

RUN_DEPENDS=	openbox:${PORTSDIR}/x11-wm/openbox \
	lxde-icon-theme>=0.5.1:${PORTSDIR}/x11-themes/lxde-icon-theme

USES=		gmake tar:xz
USE_GNOME=	gtk20 intltool intlhack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--sysconfdir=${PREFIX}/etc

.include <bsd.port.mk>

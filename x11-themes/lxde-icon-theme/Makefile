# Created by: Kris Moore <kmoore@FreeBSD.org>
# $FreeBSD: head/x11-themes/lxde-icon-theme/Makefile 351711 2014-04-21 20:27:38Z nemysis $

PORTNAME=	lxde-icon-theme
PORTVERSION=	0.5.1
CATEGORIES=	x11-themes
MASTER_SITES=	SF/lxde/LXDE%20Icon%20Theme/${DISTNAME}/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	LXDE Icon Theme

LICENSE=	LGPL3

USES=		tar:xz
NO_BUILD=	yes
INSTALLS_ICONS=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/nuoveXT2
	cd ${WRKSRC}/nuoveXT2 && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/share/icons/nuoveXT2

.include <bsd.port.mk>

# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libsysstat
PORTVERSION=	0.4.0
CATEGORIES=	sysutils
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Library used to query system info and statistics

LICENSE=	LGPL21

USES=	cmake:outsource lxqt pkgconfig tar:xz
USE_QT5=	qmake_build buildtools_build core
USE_LXQT=	buildtools

post-extract:
	@${CP} ${FILESDIR}/config.h.in ${WRKSRC};

.include <bsd.port.mk>

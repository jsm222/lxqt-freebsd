# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libsysstat
PORTVERSION=	0.3.3
CATEGORIES=	sysutils
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Library used to query system info and statistics

LICENSE=	LGPL21

USES=	cmake:outsource lxqt pkgconfig tar:xz
USE_QT5=	qmake_build buildtools_build core
USE_LXQT=	buildtools

post-extract:
	@${CP} ${FILESDIR}/config.h.in ${WRKSRC};

post-stage:
	@${CP} ${BUILD_WRKSRC}/config.h ${STAGEDIR}${LOCALBASE}/include/sysstat-qt5/config.h

.include <bsd.port.mk>

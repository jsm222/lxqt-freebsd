# Created by: Olivier Duchateau
# $FreeBSD: head/devel/lxqt-build-tools/Makefile 441215 2017-05-19 10:09:57Z joneum $

PORTNAME=	lxqt-build-tools
PORTVERSION=	0.4.0
CATEGORIES=	devel
MASTER_SITES=	LXQT/${PORTNAME}

MAINTAINER=	jesper@schmitz.computer
COMMENT=	Helpers CMake modules for LXQt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-3-Clause

USES=		cmake:outsource lxqt pkgconfig tar:xz
USE_QT5=	qmake_build buildtools_build core
USE_GNOME=	glib20

.include <bsd.port.mk>

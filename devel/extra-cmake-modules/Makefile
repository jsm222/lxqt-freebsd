# Created by Olivier Duchateau
# $FreeBSD$
#

PORTNAME=	extra-cmake-modules
PORTVERSION=	1.8.0
CATEGORIES=	devel
MASTER_SITES=	KDE/stable/frameworks/${KDE5_BRANCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extra modules and scripts for CMake

KDE5_BRANCH?=	5.8

USES=	cmake tar:xz

USE_KDE4=	# empty
CONFIGURE_ENV=	MAKE=make
CONFIGURE_ARGS=-DBUILD_HTML_DOCS:BOOL=OFF \
	-DBUILD_TESTING:BOOL=OFF

.include <bsd.port.mk>

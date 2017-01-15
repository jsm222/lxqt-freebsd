# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	lxqt-build-tools
PORTVERSION=	0.3.2
CATEGORIES=	devel
#MASTER_SITES=	LXQT/${PORTNAME}
MASTER_SITES=	https://github.com/lxde/${PORTNAME}/releases/download/${PORTVERSION}/

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Helpers CMake modules for LXQt

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/BSD-3-Clause

USES=		cmake:outsource lxqt pkgconfig tar:xz
#USE_QT5=	qmake_build buildtools_build core
NO_ARCH=	yes

.include <bsd.port.mk>

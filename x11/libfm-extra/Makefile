# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	libfm-extra
PORTVERSION=	1.2.3
CATEGORIES=	x11
MASTER_SITES=	SF/pcmanfm/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/LibFM/
DISTNAME=	libfm-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Core library of PCManFM file manager

LICENSE=	LGPL21

USES=	gmake pkgconfig pathfix libtool gettext tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 intltool intlhack
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/libfm-${PORTVERSION}

CONFIGURE_ARGS=--sysconfdir=${PREFIX}/etc --with-extra-only \
	--disable-static

.include <bsd.port.mk>

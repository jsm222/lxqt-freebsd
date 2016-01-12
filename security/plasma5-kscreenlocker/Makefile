# Created by: Tobias Berner <tcberner@gmail.com>
# $FreeBSD$

PORTNAME=	kscreenlocker
PORTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	security kde # kde-plasma

COMMENT=	Plasma5 secure lock screen architecture

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 pkgconfig tar:xz
USE_QT5=	buildtools_build core gui network qmake_build qml quick \
		testlib widgets x11extras
USE_KDE=	crash ecm emoticons globalaccel idletime init itemmodels \
		kcmutils kdeclarative kdelibs4support plasma-framework wayland
KDE_DIST=	plasma

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	YES

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000032
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ksldapp.cpp
.endif

.include <bsd.port.post.mk>

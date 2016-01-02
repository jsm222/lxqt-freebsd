# $FreeBSD$
#
# This file contains some variable definitions that are supposed to make your
# life easier, when dealing with ports related to the LXQt Desktop Environment.
#
# Feature:	lxqt
# Usage:	USES=lxqt
# Valid ARGS:	does not require args
#
# MAINTAINER: olivierd@FreeBSD.org

.if !defined(_INCLUDE_USES_LXQT_MK)
_INCLUDE_USES_LXQT_MK=	yes

.if !empty(lxqt_ARGS)
IGNORE=	Incorrect 'USES+=lxqt:${lxqt_ARGS} takes no arguments
.endif

MASTER_SITE_LXQT+= \
	http://downloads.lxqt.org/%SUBDIR%/${PORTVERSION}/
MASTER_SITE_LXQT_SUBDIR=	lxqt

.if !defined(USE_GITHUB)
MASTER_SITES?=	${MASTER_SITE_LXQT}
MASTER_SITE_SUBDIR?=	${MASTER_SITE_LXQT_SUBDIR}
.endif

DIST_SUBDIR=	lxqt

.if !defined(LICENSE)
LICENSE=	LGPL21
.endif

PLIST_SUB+=	LXQT_INCLUDEDIR="include/lxqt" \
	LXQT_SHAREDIR="share/lxqt" \
	LXQT_TRANSLATIONS="share/lxqt/translations" \
	VERSION="${PORTVERSION}"

.if !defined(LDFLAGS)
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

.if !defined(CXXFLAGS)
CXXFLAGS+=	-I${LOCALBASE}/include
.endif

# Available LXQt components are:
_USE_LXQT_ALL=	globalkeys libfmqt5 lxqt qterm qtxdg

# Not part of LXQt project, but LXDE (same developers).
_USE_LXQT_ALL+=	libfm

lxqt_LIB_DEPENDS=	liblxqt.so:${PORTSDIR}/devel/liblxqt
lxqt_USE_LXQT_REQ=	qtxdg

qtxdg_LIB_DEPENDS=	libQt5Xdg.so:${PORTSDIR}/devel/libqtxdg

globalkeys_LIB_DEPENDS=	liblxqt-globalkeys.so:${PORTSDIR}/x11/lxqt-globalkeys
globalkeys_USE_LXQT_REQ=	lxqt

libfmqt5_LIB_DEPENDS=	libfm-qt5.so:${PORTSDIR}/x11-fm/pcmanfm-qt
libfmqt5_USE_LXQT_REQ=	libfm

qterm_LIB_DEPENDS=	libqtermwidget5.so:${PORTSDIR}/x11-toolkits/qtermwidget

libfm_LIB_DEPENDS=	libfm.so:${PORTSDIR}/x11/libfm

.if defined(USE_LXQT)

# First, expand all USE_LXQT_REQ recursively.
.for comp in ${_USE_LXQT_ALL}
. for subcomp in ${${comp}_USE_LXQT_REQ}
${comp}_USE_LXQT_REQ+=	${${comp}_USE_LXQR_REQ}
. endfor
.endfor

# Then, use already expanded USE_LXQT_REQ to expand USE_LXQT.
.for comp in ${USE_LXQT}
. if ${_USE_LXQT_ALL:M${comp}} == ""
IGNORE=	cannot install: Unknown component ${comp}
. endif
_USE_LXQT+=	${${comp}_USE_LXQT_REQ} ${comp}
.endfor

# Remove duplicate components
USE_LXQT=	${_USE_LXQT:O:u}

.for comp in ${USE_LXQT}
. if defined(${comp}_BUILD_DEPENDS)
BUILD_DEPENDS+=	${${comp}_BUILD_DEPENDS}
. endif

. if defined(${comp}_LIB_DEPENDS)
LIB_DEPENDS+=	${${comp}_LIB_DEPENDS}
. endif

. if defined(${comp}_RUN_DEPENDS)
RUN_DEPENDS+=	${${comp}_RUN_DEPENDS}
. endif
.endfor

.endif # end of defined(USE_LXQT)

_USES_patch+=	750:man-post-patch

man-post-patch:
	@(cd ${WRKSRC} && ${FIND} . -type f -name 'CMakeLists.txt' \
		| ${XARGS} ${REINPLACE_CMD} -i "" 's|$${CMAKE_INSTALL_MANDIR}|man|')

.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LXQT_POST_MK)

_INCLUDE_USES_LXQT_POST_MK=	yes

.endif

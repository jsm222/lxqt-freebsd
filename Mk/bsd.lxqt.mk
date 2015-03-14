# $FreeBSD$

.if !defined(_POSTMKINCLUDED) && !defined(Lxqt_Pre_Include)

Lxqt_Include_MAINTAINER=	olivierd@FreeBSD.org
Lxqt_Pre_Include=	bsd.lxqt.mk

#
# This file contains some variable definitions that are supposed to make your
# life easier, when dealing with ports related to the LXQt Desktop Environment.
# It is automatically included when ${USE_LXQT} is defined in port's Makefile.

LXQT_VERSION?=	0.9.0
MASTER_SITE_SUBDIR?=	lxqt/${LXQT_VERSION}

PLIST_SUB+=	LXQT_INCLUDEDIR="include/lxqt/LXQt" \
	LXQT_SHAREDIR="share/lxqt"

.endif # !defined(_POSTMKINCLUDED) && !defined(Lxqt_Pre_Include)

.if defined(_POSTMKINCLUDED) && !defined(Lxqt_Pre_Include)

Lxqt_Post_Include=	bsd.lxqt.mk

# Available LXQt components are:
#
_USE_LXQT_ALL=	lxqt qtxdg

lxqt_LIB_DEPENDS=	liblxqt.so:${PORTSDIR}/x11/liblxqt
lxqt_USE_LXQT_REQ=	qtxdg

qtxdg_LIB_DEPENDS=	libQt5Xdg.so:${PORTSDIR}/devel/libqtxdg

.if defined(USE_LXQT)
# First, expand all USE_LXQT_REQ recursively.
. for comp in ${_USE_LXQT_ALL}
.  for subcomp in ${${comp}_USE_LXQT_REQ}
${comp}_USE_LXQT_REQ+=${${subcomp}_USE_LXQT_REQ}
.  endfor
. endfor

# Then, use already expanded USE_LXQT_REQ to expand USE_LXQT.
. for comp in ${USE_LXQT}
.  if ${_USE_LXQT_ALL:M${comp}} == ""
IGNORE= cannot install: Unknown component ${comp}
.  endif
_USE_LXQT+=	${${comp}_USE_LXQT_REQ} ${comp}
. endfor

# Remove duplicate components.
USE_LXQT=	${_USE_LXQT:O:u}

. for comp in ${USE_LXQT}
.  if defined(${comp}_BUILD_DEPENDS)
BUILD_DEPENDS+=	${${comp}_BUILD_DEPENDS}
.  endif

.  if defined(${comp}_LIB_DEPENDS)
LIB_DEPENDS+=	${${comp}_LIB_DEPENDS}
.  endif

.  if defined(${comp}_RUN_DEPENDS)
RUN_DEPENDS+=	${${comp}_RUN_DEPENDS}
.  endif
. endfor

.endif # defined(USE_LXQT)

.endif # defined(_POSTMKINCLUDED) && !defined(Lxqt_Pre_Include)

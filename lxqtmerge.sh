#!/bin/sh -eu
#
# Copyright (c) 2015, 2017 Olivier Duchateau <olivierd@FreeBSD.org>
# Copyright (c) 2017 Jesper Schmitz Mouridsen <jesper@schmitz.computer>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#

# Local repository
LOCAL_REPO="lxqt-freebsd"
# Version supported
BRANCH="lxqt-freebsd-import"
# The ports tree
PORTSDIR="/usr/ports"

# Git repository
GITURL="https://github.com/jsm222/lxqt-freebsd";

#### Don't change anything below

PRGFILE="`realpath "$0"`"
PRGNAME="${0##*/}"

CWD=`pwd`

err()
{
		echo "$@" >&2
		exit 1
}

usage()
{
		cat <<EOF >&2
usage: ${PRGNAME} options

options:
  -h    display this help
  -c    clone remote repository
  -m    merge into the ports tree
  -u    update local repository
  -r    revert changes
EOF
		exit 0
}

_git()
{
		which -s git
		if [ $? -eq 0 ]; then
				echo $(which git);
		else
				err "ERROR: git not found.";
		fi
		
}

update()
{
		cd ${LOCAL_REPO}
		${1} pull
}

checkout()
{
		git_cmd=$(_git)
		
		if [ ! -d "${LOCAL_REPO}/.git" ]; then
                
				${git_cmd} clone ${GITURL} $LOCAL_REPO;
                cd  ${LOCAL_REPO};
                ${git_cmd} checkout ${BRANCH};
		elif [ $git_cmd  ]; then
				update ${git_cmd};
		fi
		exit 0
}

revert()
{
		git_cmd=$(_git)

		if [ ! -d "${LOCAL_REPO}/.git" ]; then
				err "ERROR: You must clone repository first!"
		else
				if [ -n "${PORTSDIR}" ]; then
						cd ${LOCAL_REPO};
						dirs=$(find . -type d -depth 2 \
												! -path './.git*' ! -path './Tools*' ! -path './Mk*');
						for d in ${dirs}; do
								if [ -d "${PORTSDIR}/${d#./}" ]; then
										rm -Rf "${PORTSDIR}/${d#./}";
								fi
						done
						
						cd ${PORTSDIR};
						svn revert -R .;
						
						cd ${CWD};
						exit 0
				else
						err "ERROR: ${PORTSDIR} is not defined!"
				fi
		fi
}

merge()
{
		if [ ! -d "${LOCAL_REPO}/.git" ]; then
				err "ERROR: You must clone repository first!";
		else
				if [ -n "${PORTSDIR}" ]; then
						cd ${LOCAL_REPO};
						dirs=$(find . -type d -depth 2 \
												! -path './.git*' ! -path './Tools*');
						for d in ${dirs}; do
								echo "Updating '${d#./}'"

								# New port
								if [ ! -d "${PORTSDIR}/${d#./}" ]; then
										mkdir "${PORTSDIR}/${d#./}";
								fi

								# Clean port directory
								if [ -d "${PORTSDIR}/${d#./}/work" ]; then
										rm -Rf "${PORTSDIR}/${d#./}/work";
								fi
								
								# Overrides files/
								if [ -d "${PORTSDIR}/${d#./}/files" ]; then
										rm -Rf "${PORTSDIR}/${d#./}/files";
								fi

								# Copy everything
								cp -Rv ${d#./}/* ${PORTSDIR}/${d#./};
						done

						cd ${CWD};
						exit 0
				else
						err "ERROR: ${PORTSDIR} is not defined!"
				fi
		fi
}

opts=$(getopt hcmur ${*})
if [ ${?} -ne 0 ]; then
		usage
fi
set -- ${opts}

if [ ${#} -eq 1 ]; then
		usage;
else
				case "${1}" in
						-h)
								usage;
								shift
								;;
						-c)
								checkout;
								shift
								;;
						-m)
								merge;
								shift
								;;
						-u)
								checkout;
								shift
								;;
						-r)
								revert;
								shift
								;;
						--)
								shift ; break
								;;
				esac
fi

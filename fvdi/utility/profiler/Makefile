#
# Makefile for VDI profiler
#
# $Id: Makefile,v 1.2 2002-05-14 08:49:13 johan Exp $
#
# Copyright 2002, Johan Klockars
# This software is licensed under the GNU General Public License.
# Please, see LICENSE.TXT for further information.
#

all:
	sed 's#^\([[:alnum:]_]\+\)[[:space:]]\+\(equ\|set\)[[:space:]]\+\(.\+\)#.\2 \1,\3#' < vdi_prof.s | sed 's#\(text\|data\|bss\|even\|end\)#.&#' | sed 's#dc\.b[[:space:]]\+\"#.ascii "#' | sed 's#;#|#' | sed 's#\$$#0x#' > vdi_prof.gnu.s


# Copyright (C) 2011,2014 Colin Walters <walters@verbum.org>
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the
# Free Software Foundation, Inc., 59 Temple Place - Suite 330,
# Boston, MA 02111-1307, USA.

include Makefile-decls.am

ACLOCAL_AMFLAGS = -I buildutil ${ACLOCAL_FLAGS}
AM_CPPFLAGS += -DDATADIR='"$(datadir)"' -DLIBEXECDIR='"$(libexecdir)"' \
	-DGLIB_VERSION_MIN_REQUIRED=GLIB_VERSION_2_34 -DGLIB_VERSION_MAX_ALLOWED=GLIB_VERSION_2_34
AM_CFLAGS += $(WARN_CFLAGS)
DISTCHECK_CONFIGURE_FLAGS += --enable-gtk-doc --disable-maintainer-mode

SUBDIRS += .

EXTRA_DIST += autogen.sh COPYING README

if BUILDOPT_INTROSPECTION
include $(INTROSPECTION_MAKEFILE)
endif

libglnx_srcpath := $(srcdir)/libglnx
libglnx_cflags := $(BUILDDEP_GIO_UNIX_CFLAGS) -I$(libglnx_srcpath)
libglnx_libs := $(BUILDDEP_GIO_UNIX_LIBS)

noinst_LTLIBRARIES += libglnx.la
include libglnx/Makefile-libglnx.am
include Makefile-libgsystem.am
include Makefile-tests.am

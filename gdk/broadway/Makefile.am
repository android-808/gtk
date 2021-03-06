## Process this file with automake to produce Makefile.in
include $(top_srcdir)/Makefile.decl
NULL =

libgdkincludedir = $(includedir)/gtk-4.0/gdk
libgdkbroadwayincludedir = $(includedir)/gtk-4.0/gdk/broadway

AM_CPPFLAGS =				\
	-DG_LOG_DOMAIN=\"Gdk\"		\
	-DG_LOG_USE_STRUCTURED=1	\
	-DGDK_COMPILATION		\
	-I$(top_srcdir)			\
	-I$(top_srcdir)/gdk		\
	-I$(top_builddir)/gdk		\
	$(GDK_HIDDEN_VISIBILITY_CFLAGS) \
	$(GTK_DEBUG_FLAGS)		\
	$(GDK_DEP_CFLAGS)

LDADDS = $(GDK_DEP_LIBS) -lrt

noinst_LTLIBRARIES = libgdk-broadway.la

bin_PROGRAMS = gtk4-broadwayd

libgdkinclude_HEADERS = 	\
	gdkbroadway.h

libgdkbroadwayinclude_HEADERS = 	\
	gdkbroadwaydisplay.h		\
	gdkbroadwaywindow.h		\
	gdkbroadwaycursor.h		\
	gdkbroadwaymonitor.h

EXTRA_DIST += toarray.pl

clienthtml.h: client.html
	$(AM_V_GEN) $(PERL) $(srcdir)/toarray.pl client_html $(srcdir)/client.html > $@

EXTRA_DIST += client.html

broadwayjs.h: broadway.js rawinflate.min.js
	$(AM_V_GEN) $(PERL) $(srcdir)/toarray.pl broadway_js $(srcdir)/broadway.js $(srcdir)/rawinflate.min.js  > $@

EXTRA_DIST += broadway.js rawinflate.min.js

# built headers that don't get installed
broadway_built_private_headers =	\
	clienthtml.h			\
	broadwayjs.h

broadway_built_sources =		\
	${broadway_built_private_headers}

libgdk_broadway_la_SOURCES =		\
	${broadway_built_private_headers}\
	gdkcursor-broadway.c	\
	gdkdevice-broadway.h	\
	gdkdevice-broadway.c	\
	gdkdevicemanager-broadway.h \
	gdkdevicemanager-broadway.c \
	gdkdisplay-broadway.c	\
	gdkdisplay-broadway.h	\
	gdkdnd-broadway.c	\
	gdkdrawingcontext-broadway.c	\
	gdkdrawingcontext-broadway.h	\
	gdkeventsource.c	\
	gdkeventsource.h	\
	gdkglobals-broadway.c	\
	gdkkeys-broadway.c	\
	gdkmonitor-broadway.c	\
	gdkmonitor-broadway.h	\
	gdkproperty-broadway.c	\
	gdkscreen-broadway.c	\
	gdkscreen-broadway.h	\
	gdkselection-broadway.c	\
	gdktestutils-broadway.c	\
	gdkwindow-broadway.c	\
	gdkwindow-broadway.h	\
	gdkprivate-broadway.h   \
	gdkbroadway-server.h	\
	gdkbroadway-server.c

if OS_UNIX
libgdk_broadway_la_LIBADD = \
	$(SHM_LIBS)         \
	$(NULL)
endif

gtk4_broadwayd_SOURCES = \
	broadway-protocol.h		\
	broadwayd.c 			\
	broadway-server.h		\
	broadway-server.c		\
	broadway-buffer.c		\
	broadway-buffer.h		\
	broadway-output.h		\
	broadway-output.c

if OS_WIN32
gtk4_broadwayd_LDADD = $(GDK_DEP_LIBS) -lws2_32
else
gtk4_broadwayd_LDADD = $(GDK_DEP_LIBS) @SHM_LIBS@
endif

MAINTAINERCLEANFILES = $(broadway_built_sources)
EXTRA_DIST += $(broadway_built_sources)

BUILT_SOURCES = $(broadway_built_sources)

# ------------------- MSVC Build Items ----------------
MSVCPROJS = gdk4-broadway gtk4-broadwayd

gdk4_broadway_FILES = $(libgdk_broadway_la_SOURCES)
gdk4_broadway_EXCLUDES = dummy
gdk4_broadway_HEADERS_DIR = $(libgdkbroadwayincludedir)

gdk4_broadway_HEADERS_INST = $(libgdkbroadwayinclude_HEADERS)

gdk4_broadway_HEADERS_EXCLUDES = dummy

gtk4_broadwayd_FILES = $(gtk4_broadwayd_SOURCES)
gtk4_broadwayd_EXCLUDES = dummy

include $(top_srcdir)/build/Makefile.msvcproj

dist-hook: \
	$(top_builddir)/build/win32/vs12/gdk4-broadway.vcxproj		\
	$(top_builddir)/build/win32/vs12/gtk4-broadwayd.vcxproj		\
	$(top_builddir)/build/win32/vs12/gdk4-broadway.vs12.headers

-include $(top_srcdir)/git.mk

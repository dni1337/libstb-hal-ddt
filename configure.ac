AC_INIT([libstb-hal], [1.0.1])
AM_INIT_AUTOMAKE
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES])
AC_CONFIG_MACRO_DIR([m4])
AC_GNU_SOURCE

TUXBOX_APPS
TUXBOX_APPS_DIRECTORY
TUXBOX_BOXTYPE

AC_PROG_CC
AC_PROG_CXX
PKG_PROG_PKG_CONFIG
## both disabled => libtool still defaults to static
##                  at least the libtool I tested with ;-)
## --enable-shared => build only shared
## --enable-shared --enable-static => build both
AC_DISABLE_SHARED
AC_DISABLE_STATIC
AC_SYS_LARGEFILE
AC_PROG_LIBTOOL

if test x"$BOXTYPE" = x"tripledragon"; then
	PKG_CHECK_MODULES([DIRECTFB], [directfb])
fi

AC_ARG_ENABLE(gstreamer_01,
	AS_HELP_STRING(--enable-gstreamer_01, use gstreamer 0.10 playback),
	,[enable_gstreamer_01=no])

AM_CONDITIONAL(ENABLE_GSTREAMER_01,test "$enable_gstreamer_01" = "yes")
if test "$enable_gstreamer_01" = "yes"; then
	AC_DEFINE(ENABLE_GSTREAMER_01, 1, [use gstreamer 0.10 playback])
	PKG_CHECK_MODULES([GSTREAMER], [gstreamer-0.10])
	PKG_CHECK_MODULES([GSTREAMER_INTERFACES], [gstinterfaces-0.10])
fi

AC_ARG_ENABLE(gstreamer_10,
	AS_HELP_STRING(--enable-gstreamer_10, use gstreamer 1.0 playback),
	,[enable_gstreamer_10=no])

AM_CONDITIONAL(ENABLE_GSTREAMER_10, test "$enable_gstreamer_10" = "yes")
if test "$enable_gstreamer_10" = "yes"; then
	AC_DEFINE(ENABLE_GSTREAMER_10, 1, [use gstreamer 1.0 playback])
	PKG_CHECK_MODULES([GSTREAMER], [gstreamer-1.0])
	PKG_CHECK_MODULES([GSTREAMER_AUDIO], [gstreamer-audio-1.0])
	PKG_CHECK_MODULES([GSTREAMER_VIDEO], [gstreamer-video-1.0])
fi

if test x$BOXTYPE = xarmbox -a "$enable_gstreamer_10" = "yes"; then
	PKG_CHECK_MODULES([GSTREAMER], [gstreamer-1.0])
	PKG_CHECK_MODULES([GSTREAMER_AUDIO], [gstreamer-audio-1.0])
	PKG_CHECK_MODULES([GSTREAMER_VIDEO], [gstreamer-video-1.0])
fi

if test x$BOXTYPE = xgeneric -a x$BOXMODEL != xraspi; then
	PKG_CHECK_MODULES([AVFORMAT], [libavformat >= 53.21.1])
	PKG_CHECK_MODULES([AVCODEC], [libavcodec >= 54.28.0])
	# don't know which version is exactly needed here...
	PKG_CHECK_MODULES([AVUTIL], [libavutil])
	PKG_CHECK_MODULES([SWSCALE], [libswscale])
	PKG_CHECK_MODULES([SWRESAMPLE], [libswresample])
fi

AC_OUTPUT([
Makefile
common/Makefile
libeplayer3/Makefile
libeplayer3-arm/Makefile
libthread/Makefile
azbox/Makefile
generic-pc/Makefile
libduckbox/Makefile
libdvbci/Makefile
libtriple/Makefile
libspark/Makefile
libarmbox/Makefile
raspi/Makefile
tools/Makefile
])


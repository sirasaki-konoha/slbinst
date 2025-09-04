#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([SLBINST], [1.0], [sirasaki.konoha@gmail.com])

# Checks for programs.
AC_PROG_CC
AC_PROG_CC_C99

# Check compiler supporting Wall 
AC_MSG_CHECKING([wheather -Wall works])
AC_COMPILE_IFELSE(
		  [AC_LANG_PROGRAM([], [])],
		  [CFLAGS="$CFLAGS -Wall"; AC_MSG_RESULT([yes])],
		  [AC_MSG_RESULT([no])]
)
AC_MSG_CHECKING([wheather -Wextra works])
AC_COMPILE_IFELSE(
		  [AC_LANG_PROGRAM([], [])],
		  [CFLAGS="$CFLAGS -Wextra"; AC_MSG_RESULT([yes])],
		  [AC_MSG_RESULT([no])]
)
CFLAGS="$CFLAGS -Wextra -Wall"
AC_SUBST([CFLAGS])

# Checks for libraries.
PKG_PROG_PKG_CONFIG
PKG_CHECK_MODULES([CURL], [libcurl])

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT

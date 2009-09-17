#############################################################################
# Makefile for building: LogViewer
# Generated by qmake (2.01a) (Qt 4.5.2) on: Mi 16. Sep 09:01:22 2009
# Project:  LogViewer.pro
# Template: app
# Command: f:\Qt\2009.03\qt\bin\qmake.exe -spec f:/Qt/2009.03/qt/mkspecs/win32-g++ -win32 CONFIG+=debug_and_release CONFIG+=release -o Makefile LogViewer.pro
#############################################################################

first: release
install: release-install
uninstall: release-uninstall
MAKEFILE      = Makefile
QMAKE         = f:/Qt/2009.03/qt/bin/qmake.exe
DEL_FILE      = rm
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir
COPY          = cp
COPY_FILE     = $(COPY)
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = $(COPY_FILE)
INSTALL_PROGRAM = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm
SYMLINK       = 
DEL_DIR       = rmdir
MOVE          = mv
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir
SUBTARGETS    =  \
		release \
		debug

release: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_default: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-make_first: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release first
release-all: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: $(MAKEFILE).Release FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall
debug: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_default: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-make_first: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug first
debug-all: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: $(MAKEFILE).Debug FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall

Makefile: LogViewer.pro  f:/Qt/2009.03/qt/mkspecs/win32-g++/qmake.conf f:/Qt/2009.03/qt/mkspecs/qconfig.pri \
		f:/Qt/2009.03/qt/mkspecs/features/qt_functions.prf \
		f:/Qt/2009.03/qt/mkspecs/features/qt_config.prf \
		f:/Qt/2009.03/qt/mkspecs/features/exclusive_builds.prf \
		f:/Qt/2009.03/qt/mkspecs/features/default_pre.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/default_pre.prf \
		f:/Qt/2009.03/qt/mkspecs/features/release.prf \
		f:/Qt/2009.03/qt/mkspecs/features/debug_and_release.prf \
		f:/Qt/2009.03/qt/mkspecs/features/default_post.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/default_post.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/rtti.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/exceptions.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/stl.prf \
		f:/Qt/2009.03/qt/mkspecs/features/shared.prf \
		f:/Qt/2009.03/qt/mkspecs/features/warn_on.prf \
		f:/Qt/2009.03/qt/mkspecs/features/qt.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/thread.prf \
		f:/Qt/2009.03/qt/mkspecs/features/moc.prf \
		f:/Qt/2009.03/qt/mkspecs/features/win32/windows.prf \
		f:/Qt/2009.03/qt/mkspecs/features/resources.prf \
		f:/Qt/2009.03/qt/mkspecs/features/uic.prf \
		f:/Qt/2009.03/qt/mkspecs/features/yacc.prf \
		f:/Qt/2009.03/qt/mkspecs/features/lex.prf \
		f:/Qt/2009.03/qt/mkspecs/features/include_source_dir.prf \
		f:/Qt/2009.03/qt/lib/qtmain.prl
	$(QMAKE) -spec f:/Qt/2009.03/qt/mkspecs/win32-g++ -win32 CONFIG+=debug_and_release CONFIG+=release -o Makefile LogViewer.pro
f:/Qt/2009.03/qt/mkspecs/qconfig.pri:
f:/Qt/2009.03/qt/mkspecs/features/qt_functions.prf:
f:/Qt/2009.03/qt/mkspecs/features/qt_config.prf:
f:/Qt/2009.03/qt/mkspecs/features/exclusive_builds.prf:
f:/Qt/2009.03/qt/mkspecs/features/default_pre.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/default_pre.prf:
f:/Qt/2009.03/qt/mkspecs/features/release.prf:
f:/Qt/2009.03/qt/mkspecs/features/debug_and_release.prf:
f:/Qt/2009.03/qt/mkspecs/features/default_post.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/default_post.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/rtti.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/exceptions.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/stl.prf:
f:/Qt/2009.03/qt/mkspecs/features/shared.prf:
f:/Qt/2009.03/qt/mkspecs/features/warn_on.prf:
f:/Qt/2009.03/qt/mkspecs/features/qt.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/thread.prf:
f:/Qt/2009.03/qt/mkspecs/features/moc.prf:
f:/Qt/2009.03/qt/mkspecs/features/win32/windows.prf:
f:/Qt/2009.03/qt/mkspecs/features/resources.prf:
f:/Qt/2009.03/qt/mkspecs/features/uic.prf:
f:/Qt/2009.03/qt/mkspecs/features/yacc.prf:
f:/Qt/2009.03/qt/mkspecs/features/lex.prf:
f:/Qt/2009.03/qt/mkspecs/features/include_source_dir.prf:
f:\Qt\2009.03\qt\lib\qtmain.prl:
qmake: qmake_all FORCE
	@$(QMAKE) -spec f:/Qt/2009.03/qt/mkspecs/win32-g++ -win32 CONFIG+=debug_and_release CONFIG+=release -o Makefile LogViewer.pro

qmake_all: FORCE

make_default: release-make_default debug-make_default FORCE
make_first: release-make_first debug-make_first FORCE
all: release-all debug-all FORCE
clean: release-clean debug-clean FORCE
distclean: release-distclean debug-distclean FORCE
	-$(DEL_FILE) Makefile

release-mocclean: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables: $(MAKEFILE).Release
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables: $(MAKEFILE).Debug
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
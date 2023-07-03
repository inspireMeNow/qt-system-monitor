#############################################################################
# Makefile for building: QtSideBar-master
# Generated by qmake (2.01a) (Qt 4.8.5) on: ?? 7? 1 22:57:25 2023
# Project:  QtSideBar-master.pro
# Template: app
# Command: /usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/qmake -o Makefile QtSideBar-master.pro
#############################################################################

####### Compiler, tools and options

CC            = arm-linux-gcc
CXX           = arm-linux-g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/qws/linux-arm-g++ -I. -I/usr/local/Trolltech/QtEmbedded-4.8.5-arm/include/QtCore -I/usr/local/Trolltech/QtEmbedded-4.8.5-arm/include/QtNetwork -I/usr/local/Trolltech/QtEmbedded-4.8.5-arm/include/QtGui -I/usr/local/Trolltech/QtEmbedded-4.8.5-arm/include -I. -I. -I.
LINK          = arm-linux-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib -lQtGui -L/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib -lQtNetwork -lQtCore -lpthread 
AR            = arm-linux-ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = arm-linux-strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = cpuwindow.cpp \
		envwindow.cpp \
		filewindow.cpp \
		main.cpp \
		mainwindow.cpp \
		memorywindow.cpp \
		networkwindow.cpp \
		processwindow.cpp \
		sysinfowindow.cpp moc_cpuwindow.cpp \
		moc_envwindow.cpp \
		moc_filewindow.cpp \
		moc_mainwindow.cpp \
		moc_memorywindow.cpp \
		moc_networkwindow.cpp \
		moc_processwindow.cpp \
		moc_sysinfowindow.cpp \
		qrc_resources.cpp
OBJECTS       = cpuwindow.o \
		envwindow.o \
		filewindow.o \
		main.o \
		mainwindow.o \
		memorywindow.o \
		networkwindow.o \
		processwindow.o \
		sysinfowindow.o \
		moc_cpuwindow.o \
		moc_envwindow.o \
		moc_filewindow.o \
		moc_mainwindow.o \
		moc_memorywindow.o \
		moc_networkwindow.o \
		moc_processwindow.o \
		moc_sysinfowindow.o \
		qrc_resources.o
DIST          = /usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/unix.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/linux.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/qws.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/qconfig.pri \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/release.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/shared.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/moc.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/resources.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/uic.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/lex.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/include_source_dir.prf \
		QtSideBar-master.pro
QMAKE_TARGET  = QtSideBar-master
DESTDIR       = 
TARGET        = QtSideBar-master

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_cpuwindow.h ui_envwindow.h ui_filewindow.h ui_mainwindow.h ui_memorywindow.h ui_networkwindow.h ui_processwindow.h ui_sysinfowindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: QtSideBar-master.pro  /usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/qws/linux-arm-g++/qmake.conf /usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/unix.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/linux.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/gcc-base.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/gcc-base-unix.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/g++-base.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/g++-unix.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/qws.conf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/qconfig.pri \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt_functions.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt_config.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/exclusive_builds.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/default_pre.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/release.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/default_post.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/shared.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/warn_on.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/unix/thread.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/moc.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/resources.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/uic.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/yacc.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/lex.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/include_source_dir.prf \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib/libQtGui.prl \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib/libQtNetwork.prl \
		/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib/libQtCore.prl
	$(QMAKE) -o Makefile QtSideBar-master.pro
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/unix.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/linux.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/gcc-base.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/gcc-base-unix.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/g++-base.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/g++-unix.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/common/qws.conf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/qconfig.pri:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt_functions.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt_config.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/exclusive_builds.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/default_pre.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/release.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/default_post.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/shared.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/warn_on.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/qt.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/unix/thread.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/moc.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/resources.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/uic.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/yacc.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/lex.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/mkspecs/features/include_source_dir.prf:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib/libQtGui.prl:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib/libQtNetwork.prl:
/usr/local/Trolltech/QtEmbedded-4.8.5-arm/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile QtSideBar-master.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/QtSideBar-master1.0.0 || $(MKDIR) .tmp/QtSideBar-master1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/QtSideBar-master1.0.0/ && $(COPY_FILE) --parents cpuwindow.h envwindow.h filewindow.h mainwindow.h memorywindow.h networkwindow.h processwindow.h sysinfowindow.h .tmp/QtSideBar-master1.0.0/ && $(COPY_FILE) --parents resources.qrc .tmp/QtSideBar-master1.0.0/ && $(COPY_FILE) --parents cpuwindow.cpp envwindow.cpp filewindow.cpp main.cpp mainwindow.cpp memorywindow.cpp networkwindow.cpp processwindow.cpp sysinfowindow.cpp .tmp/QtSideBar-master1.0.0/ && $(COPY_FILE) --parents cpuwindow.ui envwindow.ui filewindow.ui mainwindow.ui memorywindow.ui networkwindow.ui processwindow.ui sysinfowindow.ui .tmp/QtSideBar-master1.0.0/ && (cd `dirname .tmp/QtSideBar-master1.0.0` && $(TAR) QtSideBar-master1.0.0.tar QtSideBar-master1.0.0 && $(COMPRESS) QtSideBar-master1.0.0.tar) && $(MOVE) `dirname .tmp/QtSideBar-master1.0.0`/QtSideBar-master1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/QtSideBar-master1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_cpuwindow.cpp moc_envwindow.cpp moc_filewindow.cpp moc_mainwindow.cpp moc_memorywindow.cpp moc_networkwindow.cpp moc_processwindow.cpp moc_sysinfowindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_cpuwindow.cpp moc_envwindow.cpp moc_filewindow.cpp moc_mainwindow.cpp moc_memorywindow.cpp moc_networkwindow.cpp moc_processwindow.cpp moc_sysinfowindow.cpp
moc_cpuwindow.cpp: cpuwindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) cpuwindow.h -o moc_cpuwindow.cpp

moc_envwindow.cpp: envwindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) envwindow.h -o moc_envwindow.cpp

moc_filewindow.cpp: filewindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) filewindow.h -o moc_filewindow.cpp

moc_mainwindow.cpp: memorywindow.h \
		processwindow.h \
		cpuwindow.h \
		envwindow.h \
		filewindow.h \
		networkwindow.h \
		sysinfowindow.h \
		mainwindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_memorywindow.cpp: memorywindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) memorywindow.h -o moc_memorywindow.cpp

moc_networkwindow.cpp: networkwindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) networkwindow.h -o moc_networkwindow.cpp

moc_processwindow.cpp: processwindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) processwindow.h -o moc_processwindow.cpp

moc_sysinfowindow.cpp: sysinfowindow.h
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/moc $(DEFINES) $(INCPATH) sysinfowindow.h -o moc_sysinfowindow.cpp

compiler_rcc_make_all: qrc_resources.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resources.cpp
qrc_resources.cpp: resources.qrc \
		icons/user.png \
		icons/permission.png \
		icons/settings.png
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/rcc -name resources resources.qrc -o qrc_resources.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_cpuwindow.h ui_envwindow.h ui_filewindow.h ui_mainwindow.h ui_memorywindow.h ui_networkwindow.h ui_processwindow.h ui_sysinfowindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_cpuwindow.h ui_envwindow.h ui_filewindow.h ui_mainwindow.h ui_memorywindow.h ui_networkwindow.h ui_processwindow.h ui_sysinfowindow.h
ui_cpuwindow.h: cpuwindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic cpuwindow.ui -o ui_cpuwindow.h

ui_envwindow.h: envwindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic envwindow.ui -o ui_envwindow.h

ui_filewindow.h: filewindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic filewindow.ui -o ui_filewindow.h

ui_mainwindow.h: mainwindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_memorywindow.h: memorywindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic memorywindow.ui -o ui_memorywindow.h

ui_networkwindow.h: networkwindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic networkwindow.ui -o ui_networkwindow.h

ui_processwindow.h: processwindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic processwindow.ui -o ui_processwindow.h

ui_sysinfowindow.h: sysinfowindow.ui
	/usr/local/Trolltech/QtEmbedded-4.8.5-arm/bin/uic sysinfowindow.ui -o ui_sysinfowindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

cpuwindow.o: cpuwindow.cpp cpuwindow.h \
		ui_cpuwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o cpuwindow.o cpuwindow.cpp

envwindow.o: envwindow.cpp envwindow.h \
		ui_envwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o envwindow.o envwindow.cpp

filewindow.o: filewindow.cpp filewindow.h \
		ui_filewindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o filewindow.o filewindow.cpp

main.o: main.cpp mainwindow.h \
		memorywindow.h \
		processwindow.h \
		cpuwindow.h \
		envwindow.h \
		filewindow.h \
		networkwindow.h \
		sysinfowindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		memorywindow.h \
		processwindow.h \
		cpuwindow.h \
		envwindow.h \
		filewindow.h \
		networkwindow.h \
		sysinfowindow.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

memorywindow.o: memorywindow.cpp memorywindow.h \
		ui_memorywindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o memorywindow.o memorywindow.cpp

networkwindow.o: networkwindow.cpp networkwindow.h \
		ui_networkwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o networkwindow.o networkwindow.cpp

processwindow.o: processwindow.cpp processwindow.h \
		ui_processwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o processwindow.o processwindow.cpp

sysinfowindow.o: sysinfowindow.cpp sysinfowindow.h \
		ui_sysinfowindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sysinfowindow.o sysinfowindow.cpp

moc_cpuwindow.o: moc_cpuwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_cpuwindow.o moc_cpuwindow.cpp

moc_envwindow.o: moc_envwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_envwindow.o moc_envwindow.cpp

moc_filewindow.o: moc_filewindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_filewindow.o moc_filewindow.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_memorywindow.o: moc_memorywindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_memorywindow.o moc_memorywindow.cpp

moc_networkwindow.o: moc_networkwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_networkwindow.o moc_networkwindow.cpp

moc_processwindow.o: moc_processwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_processwindow.o moc_processwindow.cpp

moc_sysinfowindow.o: moc_sysinfowindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_sysinfowindow.o moc_sysinfowindow.cpp

qrc_resources.o: qrc_resources.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resources.o qrc_resources.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

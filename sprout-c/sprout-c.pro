QT += core sql
QT -= gui

TARGET = ../../sprout/build/sproutc

CONFIG += c++11

TEMPLATE = lib

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

SOURCES += \
    src/sproutc.cpp \
    src/defines.cpp

HEADERS += \
    src/sproutc.h \
    src/defines.h

INCLUDEPATH += ../sprout-db/src
INCLUDEPATH += ../../LLVM/include

win32: LIBS += "-L../../sprout/build"
!win32: LIBS += -L../../sprout/build

LIBS += -lsproutdb

win32: LIBS += "-L../../LLVM/lib"
!win32: LIBS += -L../../LLVM/lib
LIBS += -lLLVMCore -lLLVMSupport
win32: LIBS += -limagehlp
!win32: LIBS += -ldl -ltinfo

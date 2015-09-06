QT += core
QT -= gui

TARGET = ../../sprout/lib/sproutc

CONFIG += c++11

TEMPLATE = lib

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

SOURCES += \
    src/sproutc.cpp

HEADERS += \
    src/sproutc.h

INCLUDEPATH += ../../LLVM/include

win32: LIBS += "-L../../LLVM/lib"
!win32: LIBS += -L../../LLVM/lib
LIBS += -lLLVMCore -lLLVMSupport
win32: LIBS += -limagehlp
!win32: LIBS += -ldl -ltinfo

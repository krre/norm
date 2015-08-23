QT += core sql
QT -= gui

TARGET = sprout

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/compiler.cpp

HEADERS += \
    src/global.h \
    src/compiler.h

INCLUDEPATH += ../LLVM/include

win32: LIBS += "-L../LLVM/lib"
!win32: LIBS += -L../LLVM/lib
LIBS += -lLLVMCore -lLLVMSupport -limagehlp

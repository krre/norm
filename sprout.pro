QT += core sql
QT -= gui

TARGET = sprout

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += main.cpp \
    Compiler.cpp

HEADERS += \
    global.h \
    Compiler.h

INCLUDEPATH += ../LLVM/include

win32: LIBS += "-L../LLVM/lib"
!win32: LIBS += -L../LLVM/lib
LIBS += -lLLVMCore -lLLVMSupport -limagehlp

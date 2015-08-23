QT += core sql
QT -= gui

TARGET = sprout

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

SOURCES += \
    src/Compiler.cpp \
    src/main.cpp

HEADERS += \
    src/Compiler.h \
    src/global.h

INCLUDEPATH += ../LLVM/include

win32: LIBS += "-L../LLVM/lib"
!win32: LIBS += -L../LLVM/lib
LIBS += -lLLVMCore -lLLVMSupport -limagehlp

QT += core sql
QT -= gui

TARGET = ../../sprout/build/sprout

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

win32: LIBS += "-L../../sprout/build"
!win32: LIBS += -L../../sprout/build

LIBS += -lsproutc

INCLUDEPATH += ../sprout-c/src
INCLUDEPATH += ../sprout-db/src

SOURCES += \
    src/main.cpp \



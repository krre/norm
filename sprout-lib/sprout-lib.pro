TEMPLATE = lib
SUBDIRS = app
QT += core
QT -= gui
CONFIG += c++11
TARGET = ../sprout

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

SOURCES += \
    src/main.cpp

DISTFILES += \
    ../README.md

HEADERS += \
    src/def.h


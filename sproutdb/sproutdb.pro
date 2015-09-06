QT += core sql
QT -= gui

TARGET = ../../sprout/lib/sproutdb

CONFIG += c++11

TEMPLATE = lib

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

SOURCES += \
    src/sproutdb.cpp

QT += core
QT -= gui
CONFIG += c++11
CONFIG += console
TARGET = ../sprout

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

SOURCES += \
    src/main.cpp



TEMPLATE = lib
SUBDIRS = app
QT += core
QT -= gui
CONFIG += c++11
TARGET = ../sprout

SOURCES += \
    src/main.cpp

DISTFILES += \
    ../README.md

HEADERS += \
    src/def.h


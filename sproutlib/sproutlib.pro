QT += core sql
QT -= gui

CONFIG += c++11

TARGET = sprout

TEMPLATE = lib

SOURCES += \
    src/sproutdb.cpp \
    src/project.cpp

HEADERS += \
    src/sproutdb.h \
    src/project.h

QT += core sql
QT -= gui

TARGET = sprout

CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

TEMPLATE = app

LIBS += -L$$(SPROUT_HOME)/bin
LIBS += -lsproutc -lsproutdb

INCLUDEPATH += ../sprout-c/src
INCLUDEPATH += ../sprout-db/src

SOURCES += \
    src/main.cpp \



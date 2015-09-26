QT += core sql
QT -= gui

CONFIG += c++11

Debug: TARGET = sproutd
Release: TARGET = sprout

TEMPLATE = lib

target.path += $$(SPROUT_HOME)/bin
INSTALLS += target

header_files.files += \
    src/sproutdb.h \
    src/project.h

header_files.path = $$(SPROUT_HOME)/include/sprout
INSTALLS += header_files

SOURCES += \
    src/sproutdb.cpp \
    src/project.cpp

HEADERS += \
    src/sproutdb.h \
    src/project.h

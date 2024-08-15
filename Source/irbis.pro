QT += core sql
QT -= gui

CONFIG += c++11
TARGET = irbis
TEMPLATE = app
DESTDIR = $$(IRBIS_HOME)/build

INCLUDEPATH += $$(IRBIS_HOME)/irbislib/Source

SOURCES += \
    main.cpp

HEADERS += \
    Core/Defines.h

DISTFILES += \
    ../README.md \
    ../.gitignore

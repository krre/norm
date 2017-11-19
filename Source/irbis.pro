QT += core sql

CONFIG += c++11
TARGET = irbis
TEMPLATE = app
DESTDIR = $$(IRBIS_HOME)/build

SOURCES += \
    main.cpp

HEADERS += \
    Core/Defines.h

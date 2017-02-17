QT += core
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = sproutc

target.path += $$(SPROUT_HOME)/bin
INSTALLS += target

SOURCES += \
    Source/main.cpp \
    Source/Compiler.cpp

HEADERS += \
    Source/Compiler.h \
    Source/Macro.h

OTHER_FILES += \
    .gitignore \
    README.md


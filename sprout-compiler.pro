QT += core
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = sproutc

target.path += $$(SPROUT_HOME)/bin
INSTALLS += target

SOURCES += \
    src/main.cpp \
    src/Compiler.cpp

HEADERS += \
    src/Compiler.h \
    src/Macro.h

OTHER_FILES += \
    .gitignore \
    README.md

QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH +=../../normcore/src

SOURCES += \
        main.cpp

DISTFILES += \
    ../README.md

QT += core
QT -= gui

CONFIG += c++11

TARGET = tpPointFormeApp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    point.cpp \
    forme.cpp \
    rectangle.cpp \
    cercle.cpp

HEADERS += \
    point.h \
    forme.h \
    rectangle.h \
    cercle.h

	
DESTDIR = $$PWD/../build

INCLUDEPATH += \
    $$PWD
QT += core
QT += sql
QT -= gui

CONFIG += c++11

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win32: LIBS += -LC:\wamp\bin\mysql\mysql5.7.19\lib\ -libmysql

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD -LC:\wamp\bin\mysql\mysql5.7.19\lib
DEPENDPATH += $$PWD -LC:\wamp\bin\mysql\mysql5.7.19\lib

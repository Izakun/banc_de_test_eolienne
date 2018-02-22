QT += core
QT += network
QT += sql
QT -= gui

CONFIG += c++11

TARGET = untitled
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win64: LIBS += -LC:\wamp64\bin\mysql\mysql5.7.14\ -libmysql


DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += $$PWD -LC:\wamp64\bin\mysql\mysql5.7.14
DEPENDPATH += $$PWD -LC:\wamp64\bin\mysql\mysql5.7.14

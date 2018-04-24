QT += core
QT -= gui

CONFIG += c++11

TARGET = TP_dictionnaire_app
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    dictionnaire.cpp

HEADERS += \
    dictionnaire.h

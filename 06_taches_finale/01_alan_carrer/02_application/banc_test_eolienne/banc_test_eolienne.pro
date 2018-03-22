QT += gui core network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = banc_test_eolienne
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    ceolienne.cpp

HEADERS += \
        mainwindow.h \
    ceolienne.h

FORMS += \
        mainwindow.ui

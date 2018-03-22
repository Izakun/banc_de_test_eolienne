QT += gui core network sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = application
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cscenario.cpp \
    cphase.cpp \
    ceolienne.cpp \
    csocketclient.cpp

HEADERS += \
        mainwindow.h \
    cscenario.h \
    cphase.h \
    ceolienne.h \
    csocketclient.h

FORMS += \
        mainwindow.ui

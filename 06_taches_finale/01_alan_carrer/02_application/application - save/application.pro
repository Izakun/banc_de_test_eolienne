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
    csocketclient.cpp \
    execscenario.cpp \
    createscenario.cpp \
    addeolienne.cpp

HEADERS += \
        mainwindow.h \
    cscenario.h \
    cphase.h \
    ceolienne.h \
    csocketclient.h \
    execscenario.h \
    createscenario.h \
    addeolienne.h

FORMS += \
        mainwindow.ui \
    execscenario.ui \
    createscenario.ui \
    addeolienne.ui

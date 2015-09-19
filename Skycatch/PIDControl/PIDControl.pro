#-------------------------------------------------
#
# Project created by QtCreator 2015-09-13T23:12:55
#
#-------------------------------------------------

QT       += testlib

QT       -= core gui

TARGET = PIDControl
TEMPLATE = lib
CONFIG += staticlib

SOURCES += pidcontrol.cpp \
    plant.cpp

HEADERS += pidcontrol.h \
    plant.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

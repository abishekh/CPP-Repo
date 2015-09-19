TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp


unix:!macx: LIBS += -lPIDControl

unix:!macx: LIBS += -L$$PWD/../PIDControl/ -lPIDControl

INCLUDEPATH += $$PWD/../PIDControl
DEPENDPATH += $$PWD/../PIDControl

unix:!macx: PRE_TARGETDEPS += $$PWD/../PIDControl/libPIDControl.a

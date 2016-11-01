TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt

QMAKE_CC= gcc -std=c99
 
SOURCES += main.c message_validator.c

HEADERS += \
    message_validator.h


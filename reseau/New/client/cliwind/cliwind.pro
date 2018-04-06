#-------------------------------------------------
#
# Project created by QtCreator 2018-04-06T14:10:40
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cliwind
TEMPLATE = app


SOURCES += main.cpp\
        mainwind.cpp \
        ClientTcp.cpp

HEADERS  += mainwind.h \
        ClientTcp.h

FORMS    += mainwind.ui

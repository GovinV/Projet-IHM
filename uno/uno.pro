TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    pioche.cpp \
    partie.cpp \
    joueur.cpp \
    carte.cpp \
    manche.cpp

HEADERS += \
    pioche.h \
    partie.h \
    joueur.h \
    carte.h \
    manche.h


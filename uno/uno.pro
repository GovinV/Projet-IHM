TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    pioche.cpp \
    partie.cpp \
    joueur.cpp \
    cartenombre.cpp \
    plus2.cpp \
    plus4.cpp \
    changementsens.cpp \
    changementcouleur.cpp \
    tagueule.cpp \
    carte.cpp

HEADERS += \
    pioche.h \
    partie.h \
    joueur.h \
    cartenombre.h \
    plus2.h \
    plus4.h \
    changementsens.h \
    changementcouleur.h \
    tagueule.h \
    carte.h


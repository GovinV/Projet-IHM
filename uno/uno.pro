TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    pioche.cpp \
    partie.cpp \
    joueur.cpp \
    abstractcarte.cpp \
    cartenombre.cpp \
    plus2.cpp \
    plus4.cpp \
    changementsens.cpp \
    changementcouleur.cpp \
    tagueule.cpp

HEADERS += \
    pioche.h \
    partie.h \
    joueur.h \
    abstractcarte.h \
    cartenombre.h \
    plus2.h \
    plus4.h \
    changementsens.h \
    changementcouleur.h \
    tagueule.h


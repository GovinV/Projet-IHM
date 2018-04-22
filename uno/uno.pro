TEMPLATE = app
CONFIG += console
QT += quick
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES =\
    main.cpp \
    core/types.cpp \
    core/carte.cpp \
    core/joueur.cpp \
    core/joueuria.cpp \
    core/manche.cpp \
    core/partie.cpp \
    core/pioche.cpp \
    ui/game/src/hand.cpp \
    ui/game/src/handmodel.cpp \
    ui/game/src/jeu.cpp \
    network/ClientTcp.cpp \
    ui/interface/src/network.cpp \
    ui/interface/src/playerlist.cpp \
    ui/interface/src/playermodel.cpp \
    ui/interface/src/serverlist.cpp \
    ui/interface/src/servermodel.cpp \
    ui/interface/src/settings.cpp \
    ui/interface/src/translation.cpp \

HEADERS = \
    core/types.h \
    core/carte.h \
    core/joueur.h \
    core/joueuria.h \
    core/manche.h \
    core/partie.h \
    core/pioche.h \
    ui/game/src/hand.h \
    ui/game/src/handmodel.h \
    ui/game/src/jeu.h \
    network/ClientTcp.h \
    ui/interface/src/network.h \
    ui/interface/src/playerlist.h \
    ui/interface/src/playermodel.h \
    ui/interface/src/serverlist.h \
    ui/interface/src/servermodel.h \
    ui/interface/src/settings.h \
    ui/interface/src/translation.h \

#SUBDIRS += \
#    uno.pro

RESOURCES = \
    ui/qml.qrc \
    rsc/img.qrc

TRANSLATIONS = translation/uno_en.ts

lupdate_only{
#    SOURCES = *.qml \
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

TEMPLATE = app
CONFIG += console
QT += quick
CONFIG += c++11

SOURCES += main.cpp \
    core/carte.cpp \
    core/joueur.cpp \
    core/joueuria.cpp \
    core/manche.cpp \
    core/partie.cpp \
    core/pioche.cpp \
    core/types.cpp \
    ui/hand.cpp \
    ui/handmodel.cpp \
    ui/jeu.cpp \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    core/carte.h \
    core/joueur.h \
    core/joueuria.h \
    core/manche.h \
    core/partie.h \
    core/pioche.h \
    core/types.h \
    ui/hand.h \
    ui/handmodel.h \
    ui/jeu.h

#SUBDIRS += \
#    uno.pro

RESOURCES += \
    ui/qml.qrc \
    rsc/img.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2017-03-06T16:18:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PiouPiou
TEMPLATE = app


SOURCES += main.cpp \
    map.cpp \
    player.cpp \
    ennemi.cpp \
    element.cpp \
    mur.cpp \
    sol.cpp \
    porte.cpp \
    item.cpp \
    game.cpp \
    sprite.cpp \
    scene.cpp \
    ennemyintel.cpp \
    barrelintel.cpp

HEADERS  += \
    map.h \
    player.h \
    ennemi.h \
    element.h \
    mur.h \
    sol.h \
    porte.h \
    item.h \
    game.h \
    sprite.h \
    scene.h \
    ennemyintel.h \
    barrelintel.h

FORMS    +=

RESOURCES += \
    resources.qrc

DISTFILES += \
    README.md

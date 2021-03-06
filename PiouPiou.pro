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
    element.cpp \
    game.cpp \
    sprite.cpp \
    scene.cpp \
    croco.cpp \
    barrel.cpp

HEADERS  += \
    map.h \
    player.h \
    element.h \
    game.h \
    sprite.h \
    scene.h \
    croco.h \
    barrel.h

FORMS    +=

RESOURCES += \
    resources.qrc

DISTFILES += \
    README.md

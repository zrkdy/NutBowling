#-------------------------------------------------
#
# Project created by QtCreator 2022-08-28T16:54:05
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Nutbowlingball
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainscene.cpp \
    pvzmypushbutton.cpp \
    pvzplayscene.cpp \
    Other.cpp \
    zombie.cpp \
    mower.cpp \
    basiczombie.cpp \
    nutwall.cpp \
    shop.cpp \
    card.cpp \
    map.cpp \
    footballzombie.cpp \
    rednutwall.cpp \
    bignutwall.cpp \
    boom.cpp \
    roadblockzombie.cpp \
    metalbucketzombie.cpp \
    screenzombie.cpp

HEADERS += \
        mainscene.h \
    pvzmypushbutton.h \
    pvzplayscene.h \
    Other.h \
    zombie.h \
    mower.h \
    basiczombie.h \
    nutwall.h \
    shop.h \
    card.h \
    map.h \
    footballzombie.h \
    rednutwall.h \
    bignutwall.h \
    boom.h \
    roadblockzombie.h \
    metalbucketzombie.h \
    screenzombie.h

FORMS += \
        mainscene.ui

RESOURCES += \
    image.qrc

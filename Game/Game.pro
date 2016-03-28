#-------------------------------------------------
#
# Project created by QtCreator 2016-03-08T18:45:36
#
#-------------------------------------------------

QT       += core gui\
multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp \
    game.cpp \
    player.cpp \
    background.cpp \
    laser.cpp \
    laserpool.cpp \
    enemybase.cpp \
    meteorpool.cpp \
    enemyscanner.cpp \
    basestate.cpp \
    scanstate.cpp \
    attackstate.cpp \
    enemylaser.cpp \
    enemylaserpool.cpp \
    scannerpool.cpp \
    spawnstate.cpp \
    gamestate.cpp \
    scoremanager.cpp \
    livesmanager.cpp \
    enemyboss.cpp \
    bossbasestate.cpp \
    bossspawnstate.cpp \
    bossattackpassivestate.cpp \
    soundmanager.cpp \
    bossattackagressivestate.cpp \
    messagemanager.cpp \
    enemymeteor.cpp

HEADERS  += \
    game.h \
    player.h \
    background.h \
    laser.h \
    laserpool.h \
    enemybase.h \
    meteorpool.h \
    enemyscanner.h \
    basestate.h \
    scanstate.h \
    attackstate.h \
    enemylaser.h \
    enemylaserpool.h \
    scannerpool.h \
    spawnstate.h \
    gamestate.h \
    scoremanager.h \
    livesmanager.h \
    enemyboss.h \
    bossbasestate.h \
    bossspawnstate.h \
    bossattackpassivestate.h \
    soundmanager.h \
    bossattackagressivestate.h \
    messagemanager.h \
    enemymeteor.h

RESOURCES += \
    resources.qrc

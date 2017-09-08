#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T22:05:56
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GRA
TEMPLATE = app


SOURCES += main.cpp \
    pocisk.cpp \
    wrog.cpp \
    gra.cpp \
    punkty.cpp \
    gracz.cpp \
    zdrowie.cpp \
    przycisk.cpp \
    laser.cpp \
    boss.cpp

HEADERS  += \
    pocisk.h \
    wrog.h \
    gra.h \
    punkty.h \
    gracz.h \
    zdrowie.h \
    przycisk.h \
    laser.h \
    boss.h

FORMS    += mainwindow.ui

RESOURCES += \
    zasoby.qrc

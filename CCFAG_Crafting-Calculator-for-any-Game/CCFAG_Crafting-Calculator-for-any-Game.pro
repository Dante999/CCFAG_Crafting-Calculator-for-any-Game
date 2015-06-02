#-------------------------------------------------
#
# Project created by QtCreator 2015-06-02T17:24:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CCFAG_Crafting-Calculator-for-any-Game
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    item.cpp

HEADERS  += mainwindow.h \
    database.h \
    item.h

FORMS    += mainwindow.ui

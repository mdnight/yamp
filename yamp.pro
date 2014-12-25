#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T23:01:33
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yamp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    ui/css/styles.css

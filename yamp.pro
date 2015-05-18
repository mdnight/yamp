#-------------------------------------------------
#
# Project created by QtCreator 2014-12-24T23:01:33
#
#-------------------------------------------------

QT       += core gui network

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yamp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    volumebutton.cpp \
    ui/datawidget.cpp \
    playlistwidget.cpp

HEADERS  += mainwindow.h \
    volumebutton.h \
    ui/datawidget.h \
    playlistwidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    ui/css/styles.css


unix:!macx: LIBS += -L$$PWD/libs/ -lcpp-yamusic

INCLUDEPATH += $$PWD/libs
DEPENDPATH += $$PWD/libs

unix:!macx: PRE_TARGETDEPS += $$PWD/libs/libcpp-yamusic.a

#-------------------------------------------------
#
# Project created by QtCreator 2015-02-18T14:28:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapSystem
TEMPLATE = app


SOURCES +=\
        mainwindow.cpp \
    main.cpp \
    mapeditor.cpp \
    mapviewwidget.cpp

HEADERS  += mainwindow.h \
    mapeditor.h \
    mapviewwidget.h

FORMS    += mainwindow.ui \
    mapviewwidget.ui

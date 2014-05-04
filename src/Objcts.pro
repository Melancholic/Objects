#-------------------------------------------------
#
# Project created by QtCreator 2014-05-01T11:52:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Objcts
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    drawarea.cpp \
    circle.cpp \
    entity.cpp

HEADERS  += mainwindow.h \
    drawarea.h \
    entity.h \
    circle.h

FORMS    += mainwindow.ui

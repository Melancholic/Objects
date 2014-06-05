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
    entity.cpp \
    arc.cpp \
    functions.cpp \
    square.cpp \
    circleinsquare.cpp \
    triangle.cpp \
    trinagleincircle.cpp \
    trinagleinarc.cpp

HEADERS  += mainwindow.h \
    drawarea.h \
    entity.h \
    circle.h \
    arc.h \
    functions.h \
    square.h \
    circleinsquare.h \
    triangle.h \
    trinagleincircle.h \
    trinagleinarc.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -std=c++11

DEFINES += QT_NO_DEBUG_OUTPUT

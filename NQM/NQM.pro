#-------------------------------------------------
#
# Project created by QtCreator 2016-10-01T15:11:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NQM
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    nettools.cpp

HEADERS  += mainwindow.h \
    nettools.h

LIBS += -ltins -lpthread

FORMS    += mainwindow.ui

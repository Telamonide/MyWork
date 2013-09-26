#-------------------------------------------------
#
# Project created by QtCreator 2013-05-24T01:33:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyWork
TEMPLATE = app


SOURCES += main.cpp\
    StartWindow.cpp \
    LearnWindow.cpp \
    PassWindow.cpp \
    testdialog.cpp \
    quest.cpp \
    finalwindow.cpp \
    rootchoice.cpp

HEADERS  += \
    StartWindow.h \
    LearnWindow.h \
    PassWindow.h \
    testdialog.h \
    quest.h \
    finalwindow.h \
    rootchoice.h

FORMS += \
    testdialog.ui \
    quest.ui \
    finalwindow.ui \
    rootchoice.ui

TRANSLATIONS = Work_ru.ts \

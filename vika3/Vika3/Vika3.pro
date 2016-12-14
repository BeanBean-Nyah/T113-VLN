#-------------------------------------------------
#
# Project created by QtCreator 2016-12-12T11:02:01
#
#-------------------------------------------------

QT      += core gui
QT      += sql
QT      += widgets

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Vika3
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    data.cpp \
    domain.cpp \
    facts.cpp \
    person.cpp \
    personsandcomputers.cpp \
    addnewdialog.cpp \
    dialogedit.cpp

HEADERS  += mainwindow.h \
    Computer.h \
    Data.h \
    Domain.h \
    Facts.h \
    Person.h \
    PersonsAndComputers.h \
    addnewdialog.h \
    dialogedit.h

FORMS    += mainwindow.ui \
    addnewdialog.ui \
    dialogedit.ui

RESOURCES += \
    resources.qrc

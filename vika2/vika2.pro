QT += core
QT -= gui
QT += sql

CONFIG += c++11

TARGET = vika1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    domain.cpp \
    toplayer.cpp \
    person.cpp \
    computer.cpp \
    personsandcomputers.cpp \
    facts.cpp

HEADERS += \
    Computer.h \
    Data.h \
    Domain.h \
    Facts.h \
    Person.h \
    PersonsAndComputers.h \
    TopLayer.h

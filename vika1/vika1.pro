QT += core
QT -= gui

CONFIG += c++11

TARGET = vika1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    data.cpp \
    domain.cpp \
    toplayer.cpp

HEADERS += \
    data.h \
    domain.h \
    toplayer.h

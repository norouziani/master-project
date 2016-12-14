QT += core
QT -= gui

CONFIG += c++11

TARGET = untitled10
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    receive.cpp \
    sender.cpp

HEADERS += \
    receiver.h \
    sender.h
QT += network widgets


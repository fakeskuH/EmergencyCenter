QT += core
QT -= gui

CONFIG += c++11

TARGET = EmergencyCenter
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    sensorgroup.cpp \
    sensor.cpp \
    logger.cpp \
    customsensor.cpp

HEADERS += \
    sensorgroup.h \
    isensorcomponent.h \
    sensor.h \
    logger.h \
    action.h \
    notifypolice.h \
    customsensor.h \
    smokesensor.h \
    customaction.h

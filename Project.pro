#-------------------------------------------------
#
# Project created by QtCreator 2015-03-22T11:03:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Digimon.cpp \
    Data.cpp \
    Virus.cpp \
    DigiDestined.cpp \
    Vaccine.cpp \
    ChooseDigiDestined.cpp \
    Ganador.cpp

HEADERS  += mainwindow.h \
    Digimon.h \
    Data.h \
    Virus.h \
    DigiDestined.h \
    Vaccine.h \
    ChooseDigiDestined.h \
    Ganador.h

FORMS    += mainwindow.ui \
    ChooseDigiDestined.ui \
    Ganador.ui

RESOURCES += \
    digimon.qrc

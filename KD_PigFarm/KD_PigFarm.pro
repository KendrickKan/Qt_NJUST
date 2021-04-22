#-------------------------------------------------
#
# Project created by QtCreator 2020-10-10T15:14:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KD_PigFarm
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainscene.cpp \
    allpigfarmscene.cpp \
    aboutgamescene.cpp \
    onepighome.cpp \
    kpig.cpp \
    kglobal.cpp \
    searchselllog.cpp \
    searchbuylog.cpp

HEADERS += \
        mainscene.h \
    allpigfarmscene.h \
    aboutgamescene.h \
    onepighome.h \
    kpig.h \
    kglobal.h \
    searchselllog.h \
    searchbuylog.h

FORMS += \
        mainscene.ui \
    searchselllog.ui \
    searchbuylog.ui

RESOURCES += \
    res.qrc

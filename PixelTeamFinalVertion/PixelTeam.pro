#-------------------------------------------------
#
# Project created by QtCreator 2020-11-04T20:10:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PixelTeam
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    control.cpp \
    food.cpp \
    snake.cpp \
    snakewidget.cpp \
    planemainwidget.cpp \
    planegamewidget.cpp \
    myplane.cpp \
    bullet.cpp \
    plane1.cpp \
    plane2.cpp \
    plane3.cpp \
    tetrisgamewidget.cpp \
    tetrismainwidget.cpp \
    blockcontrol.cpp \
    newblock.cpp

HEADERS += \
        mainwindow.h \
    control.h \
    food.h \
    snake.h \
    snakewidget.h \
    planemainwidget.h \
    planegamewidget.h \
    myplane.h \
    bullet.h \
    plane1.h \
    plane2.h \
    plane3.h \
    tetrismainwidget.h \
    tetrisgamewidget.h \
    blockcontrol.h \
    newblock.h

FORMS += \
        mainwindow.ui \
    tetrismainwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
UI_DIR=./UI

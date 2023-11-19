#-------------------------------------------------
#
# Project created by QtCreator 2020-07-04T21:04:29
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets sql

TARGET = keep
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        dialog.cpp \
    mainwidget.cpp \
    my_register.cpp \
    my_video.cpp \
    videowidget.cpp \
    selfinformation.cpp \
    infortable.cpp \
    schem1.cpp \
    clock_in.cpp

HEADERS += \
        dialog.h \
    mainwidget.h \
    my_register.h \
    my_video.h \
    videowidget.h \
    selfinformation.h \
    infortable.h \
    schem1.h \
    clock_in.h \
    calculate.h

FORMS += \
        dialog.ui \
    mainwidget.ui \
    my_register.ui \
    my_video.ui \
    selfinformation.ui \
    infortable.ui \
    schem1.ui \
    clock_in.ui

RESOURCES += \
    mypic.qrc

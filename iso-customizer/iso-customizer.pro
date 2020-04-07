QT += core gui dtkwidget printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iso-customizer
TEMPLATE = app

SOURCES += \
        dchoiceiso.cpp \
        main.cpp \
        mainwindow.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    dchoiceiso.h \
    mainwindow.h

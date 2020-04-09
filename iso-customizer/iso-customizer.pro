QT += core gui dtkwidget printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iso-customizer
TEMPLATE = app

SOURCES += \
        dchoicearchitecture.cpp \
        dchoiceiso.cpp \
        dlistwidgetclear.cpp \
        dmidterminstallation.cpp \
        dpreparation.cpp \
        dprogramconf.cpp \
        main.cpp \
        mainwindow.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    dchoicearchitecture.h \
    dchoiceiso.h \
    dlistwidgetclear.h \
    dmidterminstallation.h \
    dpreparation.h \
    dprogramconf.h \
    mainwindow.h

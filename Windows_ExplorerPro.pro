#-------------------------------------------------
#
# Project created by QtCreator 2014-08-20T15:27:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Windows_ExplorerPro
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    archivobase.cpp \
    carpeta.cpp \
    archivo.cpp

HEADERS  += mainwindow.h \
    Nodo.h \
    Lista.h \
    dialog.h \
    archivobase.h \
    carpeta.h \
    archivo.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    Archivos.qrc

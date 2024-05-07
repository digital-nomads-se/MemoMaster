QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    headers/mainwindow.h \
    headers/notemainwindow.h \
    headers/notecontroller.h \
    headers/notemodel.h \
    headers/noteview.h \
    headers/notememento.h \
    headers/task.h \
    headers/taskfactory.h \
    headers/todomainwindow.h \
    headers/rankedtask.h

SOURCES += \
    sources/main.cpp \
    sources/mainwindow.cpp \
    sources/notemainwindow.cpp \
    sources/task.cpp \
    sources/taskfactory.cpp \
    sources/todomainwindow.cpp \
    sources/rankedtask.cpp

FORMS += \
    mainwindow.ui \
    notemainwindow.ui \
    todomainwindow.ui


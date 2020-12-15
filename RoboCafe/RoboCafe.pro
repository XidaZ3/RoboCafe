QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Cliente.cpp \
    ClientePlus.cpp \
    ClienteStandard.cpp \
    Dipendente.cpp \
    Model.cpp \
    Risorse.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Cliente.h \
    ClientePlus.h \
    ClienteStandard.h \
    DeepPtr.h \
    Dipendente.h \
    Model.h \
    Risorse.h \
    Vettore.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

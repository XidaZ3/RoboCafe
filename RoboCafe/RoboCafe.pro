QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< Updated upstream
    Bevanda.cpp \
    Caffe.cpp \
    Model.cpp \
    Panificato.cpp \
    Pizza.cpp \
    Prodotto.cpp \
    Risorse.cpp \
    Te.cpp \
=======
    bevanda.cpp \
    caffe.cpp \
>>>>>>> Stashed changes
    main.cpp \
    mainwindow.cpp \
    panificato.cpp \
    pizza.cpp \
    prodotto.cpp \
    risorse.cpp \
    te.cpp

HEADERS += \
<<<<<<< Updated upstream
    ../../../../Users/pietr/Desktop/Classi Progetto/bevanda.h \
    ../../../../Users/pietr/Desktop/Classi Progetto/caffe.h \
    ../../../../Users/pietr/Desktop/Classi Progetto/panificato.h \
    ../../../../Users/pietr/Desktop/Classi Progetto/pizza.h \
    ../../../../Users/pietr/Desktop/Classi Progetto/prodotto.h \
    ../../../../Users/pietr/Desktop/Classi Progetto/risorse.h \
    ../../../../Users/pietr/Desktop/Classi Progetto/te.h \
    Bevanda.h \
    Caffe.h \
    DeepPtr.h \
    Model.h \
    Panificato.h \
    Pizza.h \
    Prodotto.h \
    Risorse.h \
    Te.h \
    Vettore.h \
    mainwindow.h
=======
    bevanda.h \
    caffe.h \
    mainwindow.h \
    panificato.h \
    pizza.h \
    prodotto.h \
    risorse.h \
    te.h \
    vettore.h
>>>>>>> Stashed changes

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

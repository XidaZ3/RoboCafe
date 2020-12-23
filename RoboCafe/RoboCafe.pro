QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Model/Bevanda.cpp \
    Model/Caffe.cpp \
    Model/Cliente.cpp \
    Model/ClientePlus.cpp \
    Model/ClienteStandard.cpp \
    Model/Dipendente.cpp \
    Model/Model.cpp \
    Model/Panificato.cpp \
    Model/Pizza.cpp \
    Model/Prodotto.cpp \
    Model/Risorse.cpp \
    Model/Te.cpp \
    View/MostraProdottoWidget.cpp \
    View/ProdottoItemWidget.cpp \
    View/ProdottoListWidget.cpp \
    View/View.cpp \
    View/ZonaClienteWidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Model/Bevanda.h \
    Model/Caffe.h \
    Model/Cliente.h \
    Model/ClientePlus.h \
    Model/ClienteStandard.h \
    Model/DeepPtr.h \
    Model/Dipendente.h \
    Model/Eccezioni.h \
    Model/Model.h \
    Model/Panificato.h \
    Model/Pizza.h \
    Model/Prodotto.h \
    Model/Risorse.h \
    Model/Te.h \
    Model/Vettore.h \
    View/MostraProdottoWidget.h \
    View/ProdottoItemWidget.h \
    View/ProdottoListWidget.h \
    View/View.h \
    View/ZonaClienteWidget.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

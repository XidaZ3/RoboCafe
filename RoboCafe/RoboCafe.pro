QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/Controller.cpp \
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
    View/CreaUtenteWidget.cpp \
    View/MostraProdottoWidget.cpp \
    View/OrdineItemWidget.cpp \
    View/ProdottoItemWidget.cpp \
    View/ScontrinoItemWidget.cpp \
    View/View.cpp \
    View/ZonaClienteWidget.cpp \
    View/ZonaGestoreWidget.cpp \
    main.cpp

HEADERS += \
    Controller/Controller.h \
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
    View/CreaUtenteWidget.h \
    View/CustomListWidget.h \
    View/MostraProdottoWidget.h \
    View/OrdineItemWidget.h \
    View/ProdottoItemWidget.h \
    View/ScontrinoItemWidget.h \
    View/View.h \
    View/ZonaClienteWidget.h \
    View/ZonaGestoreWidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Controller/Files/clienti.json \
    Controller/Files/menu.json \
    Files/Nuovo documento di testo.txt \
    Files/clienti.json

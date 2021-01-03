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
    View/ErroreWidget.cpp \
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
    View/ErroreWidget.h \
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
    Controller/Files/Immagini/caffe_cappuccino.PNG \
    Controller/Files/Immagini/caffe_cioccolata.PNG \
    Controller/Files/Immagini/caffe_espresso.PNG \
    Controller/Files/Immagini/caffe_latte.PNG \
    Controller/Files/Immagini/caffe_lungo.PNG \
    Controller/Files/Immagini/caffe_macchiato.PNG \
    Controller/Files/Immagini/caffe_mocaccino.PNG \
    Controller/Files/Immagini/pizza_bianca_speciale.PNG \
    Controller/Files/Immagini/pizza_bufala.PNG \
    Controller/Files/Immagini/pizza_diavola.PNG \
    Controller/Files/Immagini/pizza_funghi_peperoni.png \
    Controller/Files/Immagini/pizza_funghi_uova.PNG \
    Controller/Files/Immagini/pizza_pomodorini.PNG \
    Controller/Files/Immagini/pizza_quattro_formaggi.PNG \
    Controller/Files/Immagini/te_camomilla.PNG \
    Controller/Files/Immagini/te_matcha.PNG \
    Controller/Files/Immagini/te_menta.PNG \
    Controller/Files/Immagini/te_nero.PNG \
    Controller/Files/Immagini/te_verde.PNG \
    Controller/Files/Immagini/te_zenzero.PNG \
    Controller/Files/clienti.json \
    Controller/Files/menu.json \
    Controller/Files/model.json \
    Controller/Files/risorse.json \

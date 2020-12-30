#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QByteArray>
#include "Model/Model.h"
#include "Model/Te.h"
#include "Model/Caffe.h"
#include "Model/Pizza.h"
#include "View/View.h"
#include <QDir>
#include <Model/ClientePlus.h>
#include <Model/ClienteStandard.h>
#include <Model/Dipendente.h>
#include <QTextStream>
#include <Model/Vettore.h>
#include <Model/DeepPtr.h>

class Controller: public QObject
{
    Q_OBJECT
private:
    View *view;
    Model *model;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();
    void setView(View *value);
    void setModel(Model *value);

    void inizializzaClienteWidget() const;
    void inizializzaGestoreWidget() const;
    Vettore<Prodotto*> getProdotti() const;
    Vettore<Prodotto*> getOrdini() const;
    Vettore<Prodotto*> getErrori() const;
    void inizializzaMenu();
    void readMenuFromFile() const;
    void writeMenuToFile() const;
    void writeClientiFile() const;
    void readClientiFile() const;
public slots:
    void refillAcqua() const;
    void refillCaffe() const;
    void refillLatte() const;
    void refillTe() const;
    void refillPizze() const;
    void aggiornaStatoRisorse() const;
    void prelevaPortafoglio()const;
    void preparaOrdine();
    void confermaOrdine();
    void annullaOrdine();
    void rimuoviOrdine(int index);
    void aggiungiOrdine(Prodotto* prodottoScelto);
    void mostraSceltaProdotto(int index);
    void nuovoOrdine();
    void upgradeLivello()const;
    void convertiPunti()const;
    void upgradeUtente()const;
    void depositaCredito() const;
    void clienteSelezionato()const;
    void creaUtente() const;
    void confermaUtente() const;
    void eliminaUtente() const;
};

#endif // CONTROLLER_H

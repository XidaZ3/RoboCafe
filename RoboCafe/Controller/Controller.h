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

class Controller: public QObject
{
    Q_OBJECT
private:
    View *view;
    Model *model;

public:
    explicit Controller(QObject *parent = nullptr);
    void setView(View *value);
    void setModel(Model *value);

    void inizializzaClienteWidget() const;
    void inizializzaGestoreWidget() const;
    Vettore<Prodotto*> getProdotti();
    Vettore<Prodotto*> getOrdini();
    Vettore<Prodotto*> getErrori();
    void inizializzaMenu();
    void readMenuFromFile(string path);
    void writeMenuToFile(string path);
    void writeClienteFile() const;
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
};

#endif // CONTROLLER_H

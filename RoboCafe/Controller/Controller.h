#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model/Model.h"
#include "View/View.h"
#include <vector>

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
public slots:
    void refillAcqua() const;
    void refillCaffe() const;
    void refillLatte() const;
    void refillTe() const;
    void refillPizze() const;
    void Preleva()const;
    void preparaOrdine();
    void inizializzaMenu();
    void confermaOrdine();
    void annullaOrdine();
    void rimuoviOrdine(int index);
    void aggiungiOrdine(int index);
    void nuovoOrdine();
    std::vector<Prodotto*> getProdotti();
    std::vector<Prodotto*> getOrdini();
};

#endif // CONTROLLER_H
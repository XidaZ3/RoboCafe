#ifndef MODEL_H
#define MODEL_H

#include "Model/DeepPtr.h"
#include "Model/Vettore.h"
#include "Model/Prodotto.h"
#include "Model/Risorse.h"
#include "Model/Eccezioni.h"
#include "Model/ClientePlus.h"
#include "Model/ClienteStandard.h"
#include "Model/Dipendente.h"
#include <QFile>
#include <QJsonDocument>
#include <QTextStream>
#include "Te.h"
#include "Caffe.h"
#include "Pizza.h"
#include<string>
using std::string;

class Model
{
private:
    Vettore<DeepPtr<Prodotto>> prodotti_ordinati;
    Vettore<DeepPtr<Cliente>> clientiDb;
    Cliente* utenteAttivo;
    Vettore<DeepPtr<Prodotto>> menu;
    Vettore<DeepPtr<Prodotto>> errori;
    Risorse risorse;
    int contaClienti;
    float portafoglio;
    string scontrino;

    void readFromFile();
    void writeToFile() const;
public:
    Model();
    virtual ~Model();
    Model(const Model &m);
    Model& operator=(const Model& m);
    void stampaScontrino(Vettore<DeepPtr<Prodotto>> prodotti);
    Cliente* cercaCliente(int i);
    void ritiroConto(float s);
    void ricaricaCredito(float s);
    void preparaOrdine(Risorse& risorse);
    float calcolaTotale();
    void mostraProdotto();
    void prelevaPortafoglio(float value);
    void cancellaProdotto(int index);
    void cancellaOrdine();
    void cancellaMenu();
    void cancellaCliente(int id);
    void upgradePlus();
    void upgradeLivello();
    void aggiungiOrdine(Prodotto* prodotto);
    void aggiungiProdotto(Prodotto* prodotto);
    Cliente* aggiungiCliente(Cliente* cliente);
    Prodotto* cercaProdotto(unsigned int id);
    Vettore<DeepPtr<Prodotto>> getOrdini() const;
    Vettore<DeepPtr<Prodotto>> getProdotti()const;
    unsigned int getOrdineSize()const;
    Prodotto* getProdottoAt(int index);
    Risorse getRisorse();
    void setRisorse(const Risorse &value);
    float getPortafoglio() const;
    Vettore<DeepPtr<Prodotto>> getErrori() const;
    Cliente *getUtenteAttivo() const;
    void setUtenteAttivo(Cliente *value);
    const Vettore<DeepPtr<Cliente>>& getClientiDb() const;
    void incrementaContaClienti();
    int getContaClienti() const;
};


#endif // MODEL_H

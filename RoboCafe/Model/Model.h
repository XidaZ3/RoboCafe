#ifndef MODEL_H
#define MODEL_H

#include "Model/DeepPtr.h"
#include "Model/Vettore.h"
#include "Model/Prodotto.h"
#include "Model/Risorse.h"
#include "Model/Cliente.h"
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
    float portafoglio;
    string scontrino;
    bool terminePreparazione;

public:
    Model();
    virtual ~Model();
    Model(const Model &m);
    Model& operator=(const Model& m);
    void stampaScontrino(Vettore<DeepPtr<Prodotto>> prodotti);
    Cliente* cercaCliente(int i);
    void ritiroConto(float s);
    void ricaricaCredito(float s);
    float preparaOrdine(Risorse& risorse);
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
    void aggiungiCliente(Cliente* cliente);
    Prodotto* cercaProdotto(unsigned int id);

    Vettore<DeepPtr<Prodotto>> getOrdini() const;
    Risorse getRisorse();
    Vettore<DeepPtr<Prodotto>> getProdotti()const;
    unsigned int getOrdineSize()const;
    Prodotto* getProdottoAt(int index);
    Risorse getRisorse() const;
    void setRisorse(const Risorse &value);
    float getPortafoglio() const;
    Vettore<DeepPtr<Prodotto>> getErrori() const;
    bool getTerminePreparazione() const;
    Cliente *getUtenteAttivo() const;
    void setUtenteAttivo(Cliente *value);
    const Vettore<DeepPtr<Cliente>>& getClientiDb() const;
};


#endif // MODEL_H

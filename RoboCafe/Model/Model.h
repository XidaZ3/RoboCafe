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
    Cliente* utente;
    Vettore<DeepPtr<Prodotto>> menu;
    Risorse risorse;
    float portafoglio;
    string scontrino;
    string errori;
    bool terminePreparazione;

public:
    Model();
    virtual ~Model();
    Model(const Model &m);
    Model& operator=(const Model& m);
    void stampaScontrino(Vettore<DeepPtr<Prodotto>> prodotti);
    void ritiroConto(float s);
    float preparaOrdine(Risorse& risorse);
    void mostraProdotto();
    void prelevaPortafoglio(float value);
    void cancellaProdotto(int index);
    void cancellaOrdine();
    void cancellaMenu();
    void leggiCliente();
    void upgradePlus();
    void aggiungiOrdine(int index);
    Prodotto* cercaProdotto(unsigned int id);

    Vettore<DeepPtr<Prodotto>> getOrdini() const;
    Risorse& getRisorse();
    Vettore<DeepPtr<Prodotto>> getProdotti()const;
    unsigned int getOrdineSize()const;

    enum EccezioneRisorse{
            CreditoNonPrelevabile,
          ProdottoInesistente
        };
    Risorse& getRisorse() const;
    void setRisorse(const Risorse &value);
    float getPortafoglio() const;
    string getErrori() const;
    bool getTerminePreparazione() const;
};


#endif // MODEL_H

#ifndef MODEL_H
#define MODEL_H

#include "DeepPtr.h"
#include "Vettore.h"
#include "Prodotto.h"
#include "Risorse.h"
#include "Cliente.h"
#include<string>
using std::string;

class Model
{
private:
    Vettore<DeepPtr<Prodotto>> prodotti_ordinati;
    Cliente* utente;
    Vettore<DeepPtr<Prodotto>> menu;
    Risorse risorse;
    int portafoglio;
        string scontrino;
    string errori;
public:
    Model();
    virtual ~Model() = 0;
    Model(const Model &m);
    Model& operator=(const Model& m);
    void stampaScontrino(Vettore<DeepPtr<Prodotto>> prodotti);
    void ritiroConto();
    float preparaOrdine(Risorse& risorse);
    void mostraProdotto();
    void prelevaPortafoglio(float value);
    void cancellaProdotto(int index);
    void cancellaOrdine();
    void leggiCliente();
    void upgradePlus();
    void aggiungiOrdine(int id);
    Prodotto cercaProdotto(int id);
    void readFromFile(string path);
    void writeToFile(string path);

    enum EccezioneRisorse{
            CreditoNonPrelevabile,
          ProdottoInesistente
        };
};


#endif // MODEL_H

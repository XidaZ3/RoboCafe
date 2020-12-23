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
    int portafoglio;
        string scontrino;
    string errori;
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
    void leggiCliente();
    void upgradePlus();
    void aggiungiOrdine(int id);
    Prodotto* cercaProdotto(unsigned int id);
    void readFromFile(string path);
    void writeToFile(string path);

    enum EccezioneRisorse{
            CreditoNonPrelevabile,
          ProdottoInesistente
        };
};


#endif // MODEL_H

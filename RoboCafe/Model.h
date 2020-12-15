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

public:
    Model();
    virtual ~Model() = 0;
    Model(const Model &m);
    Model& operator=(const Model& m);
    void StampaScontrino();
    void PreparaOrdine(Risorse& risorse);
    void MostraProdotto();
    float PrelevaPortafoglio(float value);
    float DepositaPortafoglio(float value);
    void CancellaProdotto();
    void CancellaOrdine();
    void LeggiCliente();
    Prodotto CercaProdotto(int id);
    void readFromFile(string path);
    void writeToFile(string path);
};


#endif // MODEL_H

#ifndef RISORSE_H
#define RISORSE_H

#include "DeepPtr.h"
#include "Vettore.h"
#include "Prodotto.h"
#include "Risorse.h"
using std::string;

class Model
{
        private:
        vettore<DeepPtr<Prodotto>> prodotti_ordinati;
        Cliente utente;
      vettore<DeepPtr<Prodotto>> menu;
      Risorse risorse;
      int portafoglio;

        public:
        Model();
      virtual ~Model() = 0;
      Model(const Model &m);
      Model& operator=(const Model& m);
      void StampaScontrino();
      void PreparaOrdine();
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

#endif // RISORSE_H

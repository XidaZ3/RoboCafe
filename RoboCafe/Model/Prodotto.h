#ifndef PRODOTTO_H
#define PRODOTTO_H
#include <iostream>
#include <string>
#include "Model/Risorse.h"

class Prodotto
{
    private:
        unsigned int id_prodotto, quantita_rimasta, calorie;
        std::string nome_prodotto;
        float prezzo_base;

    public:
        Prodotto(unsigned int id, unsigned int quantita, std::string nome, float prezzo, unsigned int calorie = int());
        virtual ~Prodotto();
        Prodotto(const Prodotto& other);
        virtual Prodotto& operator=(const Prodotto& other);
        virtual bool operator==(const Prodotto& other)const;
        virtual Prodotto* clone() const = 0;

        virtual void Preparazione(Risorse& Risorse)const = 0;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const = 0;
        virtual std::string toString()const;

        unsigned int getCalorie() const;
        unsigned int getQuantita_rimasta() const;
        unsigned int getId_prodotto() const;
        std::string getNome_prodotto() const;
        float getPrezzo_base() const;
};

#endif // PRODOTTO_H

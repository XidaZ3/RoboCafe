#ifndef PANIFICATO_H
#define PANIFICATO_H

#include "Model/Prodotto.h"

class Panificato : public Prodotto
{
    private:
        unsigned int temperatura;

    public:
        Panificato(unsigned int id, std::string nome, float prezzo,unsigned int temp,unsigned int cal=int());
        virtual ~Panificato();
        Panificato(const Panificato& other);
        virtual Panificato& operator=(const Panificato& other);
        virtual bool operator==(const Prodotto& other) const;
        virtual Panificato* clone() const=0;

        virtual void Preparazione(Risorse& Risorse)const =0;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string getDettagli() const;
        virtual std::string toString()const;

        int getTemperatura() const;
        void setTemperatura(int value);
};

#endif // PANIFICATO_H

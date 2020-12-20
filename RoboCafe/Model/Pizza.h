#ifndef PIZZA_H
#define PIZZA_H

#include "Panificato.h"

enum class Dimensione {Piccola, Media, Grande};

class Pizza : public Panificato
{
    private:
        Dimensione dimensione;
    public:
        Pizza(unsigned int id, unsigned int quantita, std::string nome, float prezzo,unsigned int temp,unsigned int cal=int(), bool ex=false, Dimensione dim=Dimensione::Media);
        virtual ~Pizza();
        Pizza(const Pizza& other);
        virtual Pizza& operator=(const Pizza& other);
        virtual bool operator==(const Pizza& other) const;
        virtual Pizza* clone() const ;

        virtual void Preparazione(Risorse& Risorse)const ;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string toString()const;
        Dimensione getDimensione() const;
        void setDimensione(const Dimensione &value);
};

#endif // PIZZA_H

#ifndef TE_H
#define TE_H

#include "Bevanda.h"

class Te : public Bevanda
{
    private:
        int filtri;
        bool limone;
    public:
        Te(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal=int(),
           float l = 0, int caf =0, bool gh =0,Dimensione dim = Dimensione::Medio, int fil = 1, bool lim = false);
        virtual ~Te();
        Te(const Te& other);
        virtual Te& operator= (const Te& other);
        virtual bool operator==(const Te& other) const;
        virtual Te* clone() const;

        virtual void Preparazione(Risorse& Risorse)const;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string toString()const;


        int getFiltri() const;
        void setFiltri(int value);
        bool getLimone() const;
        void setLimone(bool value);
};

#endif // TE_H

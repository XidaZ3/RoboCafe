#ifndef BEVANDA_H
#define BEVANDA_H

#include "Model/Prodotto.h"


class Bevanda : public Prodotto
{
    private:
    float acqua;
    bool ghiaccio;

    public:
        Bevanda(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal=int(),Dimensione dim = Dimensione::Medio,
                 bool gh =0);
        virtual ~Bevanda();
        Bevanda(const Bevanda& other);
        virtual Bevanda& operator= (const Bevanda& other);
        virtual bool operator==(const Bevanda& other) const;
        virtual Bevanda* clone() const =0;

        virtual void Preparazione(Risorse& Risorse)const =0;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string getDettagli() const;
        virtual std::string toString()const;

        float getAcqua() const;
        void setAcqua(float value);
        bool getGhiaccio() const;
        void setGhiaccio(bool value);

};

#endif // BEVANDA_H

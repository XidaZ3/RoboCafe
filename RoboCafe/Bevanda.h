#ifndef BEVANDA_H
#define BEVANDA_H

#include "Prodotto.h"

enum class Dimensione{Piccolo, Medio,Grande};

class Bevanda : public Prodotto
{
    private:
    float acqua, latte;
    int caffe;
    bool ghiaccio;
    Dimensione dimensione;
    public:
        Bevanda(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal=int(),
                float l = 0, int caf =0, bool gh =0,Dimensione dim = Dimensione::Medio);
        virtual ~Bevanda();
        Bevanda(const Bevanda& other);
        virtual Bevanda& operator= (const Bevanda& other);
        virtual bool operator==(const Bevanda& other) const;
        virtual Bevanda* clone() const =0;

        virtual bool Preparazione(Risorse& Risorse)const =0;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string toString()const;

        float getAcqua() const;
        void setAcqua(float value);
        float getLatte() const;
        void setLatte(float value);
        int getCaffe() const;
        void setCaffe(int value);
        bool getGhiaccio() const;
        void setGhiaccio(bool value);
};

#endif // BEVANDA_H

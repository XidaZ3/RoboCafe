#ifndef BEVANDA_H
#define BEVANDA_H

#include "Model/Prodotto.h"


class Bevanda : public Prodotto
{
    private:
    float acqua;
    bool ghiaccio;

    public:
        Bevanda(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal=int(),Dimensione dim = Dimensione::Medio,bool gh =0);
        Bevanda();
        virtual ~Bevanda();
        Bevanda(const Bevanda& other);
        virtual Bevanda& operator= (const Bevanda& other);
        virtual bool operator==(const Bevanda& other) const;
        virtual bool operator!=(const Bevanda& other) const;
        virtual Bevanda* clone() const =0;

        virtual void preparazione(Risorse& Risorse)const =0;
        virtual float calcoloPrezzo() const;
        virtual int calcoloEnergia()const;
        virtual Vettore<std::string> getDettagli() const;
        virtual std::string toString() const;
        virtual void read(const QJsonObject& json);
        virtual void write(QJsonObject& json) const;

        float getAcqua() const;
        void setAcqua(float value);
        bool getGhiaccio() const;
        void setGhiaccio(bool value);

};

#endif // BEVANDA_H

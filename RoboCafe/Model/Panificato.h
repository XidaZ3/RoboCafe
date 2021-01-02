#ifndef PANIFICATO_H
#define PANIFICATO_H

#include "Model/Prodotto.h"

class Panificato : public Prodotto
{
    private:
        unsigned int temperatura;

    public:
        Panificato(unsigned int id,std::string path, std::string nome, float prezzo,unsigned int temp,unsigned int cal=int(),Dimensione dim = Dimensione::Medio);
        Panificato();
        virtual ~Panificato();
        Panificato(const Panificato& other);
        virtual Panificato& operator=(const Panificato& other);
        virtual bool operator==(const Prodotto& other) const;
        virtual Panificato* clone() const=0;

        virtual void preparazione(Risorse& Risorse)const =0;
        virtual float calcoloPrezzo() const;
        virtual int calcoloEnergia()const;
        virtual Vettore<std::string> getDettagli() const;
        virtual std::string toString() const;
        virtual void read(const QJsonObject& json);
        virtual void write(QJsonObject& json) const;

        int getTemperatura() const;
        void setTemperatura(int value);
};

#endif // PANIFICATO_H

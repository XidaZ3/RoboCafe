#ifndef PIZZA_H
#define PIZZA_H

#include "Model/Panificato.h"
#include <string>


class Pizza : public Panificato
{
    private:
        bool extra;
    public:
        Pizza(unsigned int id,std::string path, std::string nome, float prezzo,unsigned int temp,unsigned int cal=int(), bool ex=false);
        Pizza();
        virtual ~Pizza();
        Pizza(const Pizza& other);
        virtual Pizza& operator=(const Pizza& other);
        virtual bool operator==(const Pizza& other) const;
        virtual bool operator!=(const Pizza& other) const;
        virtual Pizza* clone() const ;

        virtual void preparazione(Risorse& Risorse)const ;
        virtual float calcoloPrezzo() const;
        virtual int calcoloEnergia()const;
        virtual Vettore<std::string> getDettagli() const;
        virtual std::string toString() const;
        virtual void read(const QJsonObject& json);
        virtual void write(QJsonObject& json) const;
        bool getExtra() const;
        void setExtra(bool value);
};

#endif // PIZZA_H

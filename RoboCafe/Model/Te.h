#ifndef TE_H
#define TE_H

#include "Model/Bevanda.h"

class Te : public Bevanda
{
    private:
        float latte;
        int filtri;
        bool limone;
    public:
        Te(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal=int(),Dimensione dim = Dimensione::Medio, bool gh =0,float latte=0, int fil = 1, bool lim = false);
        Te();
        virtual ~Te();
        Te(const Te& other);
        virtual Te& operator= (const Te& other);
        virtual bool operator==(const Te& other) const;
        virtual bool operator!=(const Te& other) const;
        virtual Te* clone() const;

        virtual void preparazione(Risorse& Risorse)const;
        virtual float calcoloPrezzo() const;
        virtual int calcoloEnergia()const;
        virtual Vettore<std::string> getDettagli() const;
        virtual std::string toString() const;
        virtual void read(const QJsonObject& json);
        virtual void write(QJsonObject& json) const;


        int getFiltri() const;
        void setFiltri(int value);
        bool getLimone() const;
        void setLimone(bool value);
        float getLatte() const;
        void setLatte(float value);
};

#endif // TE_H

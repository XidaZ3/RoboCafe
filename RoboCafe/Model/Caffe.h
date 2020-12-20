#ifndef CAFFE_H
#define CAFFE_H

#include "Bevanda.h"

class Caffe : public Bevanda
{
    private:
        bool cacao,caramello;
    public:
        Caffe(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal=int(),
           float l = 0, int caf =0, bool gh =0,Dimensione dim = Dimensione::Medio, bool ca = false, bool cara = false);
        virtual ~Caffe();
        Caffe(const Caffe& other);
        virtual Caffe& operator= (const Caffe& other);
        virtual bool operator==(const Caffe& other) const;
        virtual Caffe* clone() const;

        virtual void Preparazione(Risorse& Risorse)const;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string toString()const;

        bool getCacao() const;
        void setCacao(bool value);
        bool getCaramello() const;
        void setCaramello(bool value);
};

#endif // CAFFE_H

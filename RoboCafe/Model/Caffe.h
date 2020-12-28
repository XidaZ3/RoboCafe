#ifndef CAFFE_H
#define CAFFE_H

#include "Model/Bevanda.h"

class Caffe : public Bevanda
{
    private:
        float latte;
        int cialdeCaffe;
        bool cacao,caramello;
    public:
        Caffe(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal=int(),Dimensione dim = Dimensione::Medio,
            bool gh =0,float l = 0, int caf =0, bool ca = false, bool cara = false);
        virtual ~Caffe();
        Caffe(const Caffe& other);
        virtual Caffe& operator= (const Caffe& other);
        virtual bool operator==(const Caffe& other) const;
        virtual Caffe* clone() const;

        virtual void Preparazione(Risorse& Risorse)const;
        virtual float CalcoloPrezzo() const;
        virtual int CalcoloEnergia()const;
        virtual std::string getDettagli() const;
        virtual std::string toString() const;
        virtual std::string toJsonString()const;

        bool getCacao() const;
        void setCacao(bool value);
        bool getCaramello() const;
        void setCaramello(bool value);
        float getLatte() const;
        void setLatte(float value);
        int getCialdeCaffe() const;
        void setCialdeCaffe(int value);
};

#endif // CAFFE_H

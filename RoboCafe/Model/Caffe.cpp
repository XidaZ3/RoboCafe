#include "Model/Caffe.h"
#include <string>

Caffe::Caffe(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal,
                 float l, int caf, bool gh,Dimensione dim, bool ca, bool cara):
    Bevanda(id, quantita, nome, prezzo, cal, ac, l, caf, gh, dim), cacao(ca), caramello(cara){}

Caffe::Caffe(const Caffe &other)=default;

Caffe::~Caffe()=default;

Caffe &Caffe::operator=(const Caffe &other)=default;

bool Caffe::operator==(const Caffe &other) const
{
    return Bevanda::operator==(other) && cacao==static_cast<const Caffe&>(other).cacao && caramello == static_cast<const Caffe&>(other).caramello;
}

Caffe *Caffe::clone() const
{
    return new Caffe(*this);
}

void Caffe::Preparazione(Risorse &Risorse) const
{
    switch (getDimensione()) {
        case Dimensione::Piccolo: Risorse.subAcqua(getAcqua()*0.7); Risorse.subCaffe(1); Risorse.subLatte(getLatte());
        case Dimensione::Medio: Risorse.subAcqua(getAcqua()); Risorse.subCaffe(2); Risorse.subLatte(getLatte());
        case Dimensione::Grande: Risorse.subAcqua(getAcqua()*1.2); Risorse.subCaffe(3); Risorse.subLatte(getLatte());
    }
}

float Caffe::CalcoloPrezzo() const
{
    return this->Bevanda::CalcoloPrezzo() + (cacao && caramello ? 1 : 0);
}

int Caffe::CalcoloEnergia() const
{
    return Bevanda::CalcoloEnergia() + (cacao ? 5 : 0);
}

std::string Caffe::toString() const
{
    std::string ret = this->Bevanda::toString() + "\n\t\tCacao: "+(cacao ? "Si": "No")+"\tCaramello: "+(caramello ? "Si": "No");
    return ret;
}

bool Caffe::getCaramello() const
{
    return caramello;
}

void Caffe::setCaramello(bool value)
{
    caramello = value;
}

bool Caffe::getCacao() const
{
    return cacao;
}

void Caffe::setCacao(bool value)
{
    cacao = value;
}

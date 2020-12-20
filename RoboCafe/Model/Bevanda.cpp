#include "Model/Bevanda.h"

Dimensione Bevanda::getDimensione() const
{
    return dimensione;
}

void Bevanda::setDimensione(const Dimensione &value)
{
    dimensione = value;
}

Bevanda::Bevanda(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal,
                 float l, int caf, bool gh,Dimensione dim):
    Prodotto(id, quantita, nome, prezzo, cal), acqua(ac), latte(l), caffe(caf),ghiaccio(gh), dimensione(dim){}

Bevanda::Bevanda(const Bevanda &other)=default;

Bevanda::~Bevanda()=default;

Bevanda &Bevanda::operator=(const Bevanda &other)=default;

bool Bevanda::operator==(const Bevanda &other) const
{
    return Prodotto::operator==(other) && acqua == static_cast<const Bevanda&>(other).acqua && latte == static_cast<const Bevanda&>(other).latte &&
            caffe == static_cast<const Bevanda&>(other).caffe && ghiaccio == static_cast<const Bevanda&>(other).ghiaccio &&
            dimensione == static_cast<const Bevanda&>(other).dimensione ;
}

float Bevanda::CalcoloPrezzo() const
{
    int sizePrice = 0;
    switch (dimensione) {
        case Dimensione::Piccolo: sizePrice -=1;
        case Dimensione::Medio: ;
        case Dimensione::Grande: sizePrice += 1;
    }
    return this->Prodotto::CalcoloPrezzo() + (acqua+latte)/100.0 + caffe+sizePrice;
}

int Bevanda::CalcoloEnergia() const
{
    return (acqua + latte + caffe)/30;
}

std::string Bevanda::toString() const
{
    std::string ret = this->Prodotto::toString() + "\n\tAcqua: "+std::to_string(acqua)+"\tLatte: "+std::to_string(latte)+
            "\tCaffe: "+std::to_string(caffe)+"\tGhiaccio: "+(ghiaccio ? "Si": "No")+"\tDimensione: "+std::to_string(static_cast<int>(dimensione));
    return ret;
}

float Bevanda::getAcqua() const
{
    return acqua;
}

void Bevanda::setAcqua(float value)
{
    acqua = value;
}

float Bevanda::getLatte() const
{
    return latte;
}

void Bevanda::setLatte(float value)
{
    latte = value;
}

int Bevanda::getCaffe() const
{
    return caffe;
}

void Bevanda::setCaffe(int value)
{
    caffe = value;
}

bool Bevanda::getGhiaccio() const
{
    return ghiaccio;
}

void Bevanda::setGhiaccio(bool value)
{
    ghiaccio = value;
}

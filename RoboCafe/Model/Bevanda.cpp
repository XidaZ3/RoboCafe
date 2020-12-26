#include "Model/Bevanda.h"

Bevanda::Bevanda(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal,Dimensione dim, bool gh):
    Prodotto(id, quantita, nome, prezzo, cal, dim), acqua(ac),ghiaccio(gh){}

Bevanda::Bevanda(const Bevanda &other)=default;

Bevanda::~Bevanda()=default;

Bevanda &Bevanda::operator=(const Bevanda &other)=default;

bool Bevanda::operator==(const Bevanda &other) const
{
    return Prodotto::operator==(other) && acqua == static_cast<const Bevanda&>(other).acqua && ghiaccio == static_cast<const Bevanda&>(other).ghiaccio;
}

float Bevanda::CalcoloPrezzo() const
{
    int sizePrice = 0;
    switch (getDimensione()) {
        case Dimensione::Piccolo: sizePrice -=1;break;
        case Dimensione::Medio: ;break;
        case Dimensione::Grande: sizePrice += 1;break;
        default:;
    }
    return this->Prodotto::CalcoloPrezzo() + (acqua)/100.0;
}

int Bevanda::CalcoloEnergia() const
{
    return (acqua)/30;
}

std::string Bevanda::getDettagli() const
{
    return Prodotto::getDettagli() + (ghiaccio ? "Ghiaccio,": "");
}

std::string Bevanda::toString() const
{
    std::string ret = this->Prodotto::toString() +
            "\n\t\t\"Bevanda\": {\n\t\t\t\"acqua\": "+std::to_string(getAcqua())+",\n\t\t\t\"ghiaccio\": \""+(ghiaccio? "true":"false")+"\",";
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

bool Bevanda::getGhiaccio() const
{
    return ghiaccio;
}

void Bevanda::setGhiaccio(bool value)
{
    ghiaccio = value;
}

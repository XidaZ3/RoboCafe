#include "Model/Te.h"
#include <string>

Te::Te(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal,Dimensione dim, bool gh,float l, int fil, bool lim):
    Bevanda(id, quantita, nome, prezzo, ac,cal, dim, gh),latte(l),filtri(fil), limone(lim){}

Te::Te(const Te &other)=default;

Te::~Te()=default;

Te &Te::operator=(const Te &other)=default;

bool Te::operator==(const Te &other) const
{
    return Bevanda::operator==(other)&&latte == static_cast<const Te&>(other).latte && filtri==static_cast<const Te&>(other).filtri && limone == static_cast<const Te&>(other).limone;
}

Te *Te::clone() const
{
    return new Te(*this);
}

void Te::Preparazione(Risorse &Risorse) const
{
    switch (getDimensione()) {
        case Dimensione::Piccolo: Risorse.subAcqua(getAcqua()*0.7); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());
        case Dimensione::Medio: Risorse.subAcqua(getAcqua()); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());
        case Dimensione::Grande: Risorse.subAcqua(getAcqua()*1.2); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());
        default:;
    }
}

float Te::CalcoloPrezzo() const
{
    return this->Bevanda::CalcoloPrezzo() + latte/100 + filtri;
}

int Te::CalcoloEnergia() const
{
    //TODO
    return 1;
}

std::string Te::getDettagli() const
{
    return Bevanda::getDettagli() + "Filtri: x"+std::to_string(filtri)+","+(limone? "Limone,":"");
}

std::string Te::toString() const
{
    std::string ret = this->Bevanda::toString() +"\n\t\tFiltri: "+std::to_string(latte)+ "\t\tFiltri: "+std::to_string(filtri)+"\tLimone: "+(limone ? "Si": "No");
    return ret;
}
int Te::getFiltri() const
{
    return filtri;
}

void Te::setFiltri(int value)
{
    filtri = value;
}

bool Te::getLimone() const
{
    return limone;
}

void Te::setLimone(bool value)
{
    limone = value;
}

float Te::getLatte() const
{
    return latte;
}

void Te::setLatte(float value)
{
    latte = value;
}

#include "Model/Te.h"
#include <string>

Te::Te(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal,Dimensione dim, bool gh,float l, int fil, bool lim):
    Bevanda(id,path, nome, prezzo, ac,cal, dim, gh),latte(l),filtri(fil), limone(lim){}

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
        case Dimensione::Piccolo: Risorse.subAcqua(getAcqua()*0.7); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());break;
        case Dimensione::Medio: Risorse.subAcqua(getAcqua()); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());break;
        case Dimensione::Grande: Risorse.subAcqua(getAcqua()*1.2); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());break;
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
    return Bevanda::toString()+"\n\n\tFiltriTe: "+std::to_string(getFiltri())+"\tLatte: "+std::to_string(getLatte())+"\tLimone: "+(limone ? "Si" : "No");
}

std::string Te::toJsonString() const
{
    std::string prec= Bevanda::toJsonString();
    std::string value="\n\t\t\"te\" : {"
            "\n\t\t\t\"latte\": "+std::to_string(latte)+ ",\n\t\t\t\"filtriTe\": "+std::to_string(filtri)+",\n\t\t\t\"limone\" : \""+(limone ? "true":"false")+"\"}";
    std::string ret = prec.insert(prec.size()-2,value);
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

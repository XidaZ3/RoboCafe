#include "Model/Te.h"
#include <string>

Te::Te(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal,Dimensione dim, bool gh,float l, int fil, bool lim):
    Bevanda(id,path, nome, prezzo, ac,cal, dim, gh),latte(l),filtri(fil), limone(lim){}

Te::Te():latte(),filtri(),limone(){}

Te::Te(const Te &other)=default;

Te::~Te()=default;

Te &Te::operator=(const Te &other)=default;

bool Te::operator==(const Te &other) const
{
    return Bevanda::operator==(other)&&latte == static_cast<const Te&>(other).latte && filtri==static_cast<const Te&>(other).filtri && limone == static_cast<const Te&>(other).limone;
}

bool Te::operator!=(const Te &other) const
{
    return !(Bevanda::operator==(other)&&latte == static_cast<const Te&>(other).latte && filtri==static_cast<const Te&>(other).filtri && limone == static_cast<const Te&>(other).limone);

}

Te *Te::clone() const
{
    return new Te(*this);
}

void Te::preparazione(Risorse &Risorse) const
{
    switch (getDimensione()) {
        case Dimensione::Piccolo: Risorse.subAcqua(getAcqua()*0.7); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());break;
        case Dimensione::Medio: Risorse.subAcqua(getAcqua()); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());break;
        case Dimensione::Grande: Risorse.subAcqua(getAcqua()*1.2); Risorse.subTe(getFiltri()); Risorse.subLatte(getLatte());break;
        default:;
    }
}

float Te::calcoloPrezzo() const
{
    return this->Bevanda::calcoloPrezzo() + filtri-1;
}

int Te::calcoloEnergia() const
{
    //TODO
    return 1;
}

Vettore<std::string> Te::getDettagli() const
{
    Vettore<std::string> prec = Bevanda::getDettagli();
    prec.push_back("Filtri: x"+std::to_string(filtri));
    if(limone)
        prec.push_back("Limone");
    return prec;
}

std::string Te::toString() const
{
    return Bevanda::toString()+"\n\n\tFiltriTe: "+std::to_string(getFiltri())+"\tLatte: "+std::to_string(getLatte())+"\tLimone: "+(limone ? "Si" : "No");
}

void Te::read(const QJsonObject &json)
{
    Bevanda::read(json);
    filtri = json["filtriTe"].toInt();
    latte = json["latte"].toDouble();
    limone = json["limone"].toBool();
}

void Te::write(QJsonObject &json) const
{
    Bevanda::write(json);
    QJsonObject te;
    te["filtriTe"] = filtri;
    te["latte"] = latte;
    te["limone"] = limone;
    json["te"] = te;
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

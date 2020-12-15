#include "Te.h"
#include <string>

Te::Te(unsigned int id, unsigned int quantita, std::string nome, float prezzo,float ac,unsigned int cal,
                 float l, int caf, bool gh,Dimensione dim, int fil, bool lim):
    Bevanda(id, quantita, nome, prezzo, cal, ac, l, caf, gh, dim), filtri(fil), limone(lim){}

Te::Te(const Te &other)=default;

Te::~Te()=default;

Te &Te::operator=(const Te &other)=default;

bool Te::operator==(const Te &other) const
{
    return this->Bevanda::operator==(other) && filtri==other.filtri && limone == other.limone;
}

Te *Te::clone() const
{
    return new Te(*this);
}

bool Te::Preparazione(Risorse &Risorse) const
{
    //TODO
    return 1;
}

float Te::CalcoloPrezzo() const
{
    return this->Bevanda::CalcoloPrezzo() + filtri;
}

int Te::CalcoloEnergia() const
{
    //TODO
    return 1;
}

std::string Te::toString() const
{
    std::string ret = this->Bevanda::toString() + "\n\t\tFiltri: "+std::to_string(filtri)+"\tLimone: "+(limone ? "Si": "No");
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

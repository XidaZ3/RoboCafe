#include "Model/Pizza.h"
#include <string>

Pizza::Pizza(unsigned int id, std::string nome, float prezzo,unsigned int temp,unsigned int cal, bool ex):
    Panificato(id, nome, prezzo,temp, cal), extra(ex){}

Pizza::~Pizza() = default;

bool Pizza::getExtra() const
{
    return extra;
}

void Pizza::setExtra(bool value)
{
    extra = value;
}

Pizza::Pizza(const Pizza &other): Panificato(other)
{
    extra = other.extra;
}
Pizza &Pizza::operator=(const Pizza &other)=default;

bool Pizza::operator==(const Pizza &other) const
{
    return Panificato::operator==(other) && extra == static_cast<const Pizza&>(other).extra;
}

Pizza *Pizza::clone() const
{
    return new Pizza(*this);
}

void Pizza::Preparazione(Risorse &Risorse) const
{
    switch (getDimensione()) {
        case Dimensione::Piccolo: Risorse.subPizza(1);break;
        case Dimensione::Medio: Risorse.subPizza(2);break;
        case Dimensione::Grande: Risorse.subPizza(3);break;
        default:;
    }
}

float Pizza::CalcoloPrezzo() const
{
    int sizePrice=0;
    switch (getDimensione()) {
        case Dimensione::Piccolo: sizePrice +=1;break;
        case Dimensione::Medio:break;
        case Dimensione::Grande: sizePrice -= 1;break;
    }
    return this->Panificato::CalcoloPrezzo()+sizePrice+(extra? 1:0);
}

int Pizza::CalcoloEnergia() const
{
    return Panificato::CalcoloEnergia() * (static_cast<int>(getDimensione())+2);
}

std::string Pizza::getDettagli() const
{
    return Panificato::getDettagli()+(extra ? "Extra," :"");
}

std::string Pizza::toString() const
{
    std::string ret = this->Panificato::toString() + "\n\t\tExtra: "+(extra? "Si":"No");
    return ret;
}



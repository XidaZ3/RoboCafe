#include "Model/Pizza.h"
#include <string>

Pizza::Pizza(unsigned int id, unsigned int quantita, std::string nome, float prezzo,unsigned int temp,unsigned int cal, bool ex, Dimensione dim):
    Panificato(id, quantita, nome, prezzo,temp, cal,ex ), dimensione(dim){}

Pizza::~Pizza() = default;

Pizza::Pizza(const Pizza &other): Panificato(other)
{
    dimensione = other.dimensione;
}
Pizza &Pizza::operator=(const Pizza &other)=default;

bool Pizza::operator==(const Pizza &other) const
{
    return Panificato::operator==(other) && dimensione == static_cast<const Pizza&>(other).dimensione;
}

Pizza *Pizza::clone() const
{
    return new Pizza(*this);
}

void Pizza::Preparazione(Risorse &Risorse) const
{
    switch (dimensione) {
        case Dimensione::Piccola: Risorse.subPizza(1);
        case Dimensione::Media: Risorse.subPizza(2);
        case Dimensione::Grande: Risorse.subPizza(3);
    }
}

float Pizza::CalcoloPrezzo() const
{
    int sizePrice=0;
    switch (dimensione) {
        case Dimensione::Piccola: sizePrice +=1;
        case Dimensione::Media: ;
        case Dimensione::Grande: sizePrice -= 1;
    }
    return this->Panificato::CalcoloPrezzo()+sizePrice;
}

int Pizza::CalcoloEnergia() const
{
    return Panificato::CalcoloEnergia() * (static_cast<int>(dimensione)+2);
}

std::string Pizza::toString() const
{
    std::string ret = this->Panificato::toString() + "\n\t\tDimensione: "+std::to_string(static_cast<int>(dimensione));
    return ret;
}

Dimensione Pizza::getDimensione() const
{
    return dimensione;
}

void Pizza::setDimensione(const Dimensione &value)
{
    dimensione = value;
}


#include "Panificato.h"

Panificato::Panificato(unsigned int id, unsigned int quantita, std::string nome, float prezzo,unsigned int temp,unsigned int cal, bool ex):
    Prodotto(id,quantita,nome, prezzo, cal),
    temperatura(temp), extra(ex){}

Panificato::~Panificato()= default;

Panificato::Panificato(const Panificato &other) = default;

Panificato &Panificato::operator=(const Panificato &other)=default;

bool Panificato::operator==(const Panificato &other) const
{
    return this->Prodotto::operator==(other) && temperatura == other.getTemperatura() && extra == other.getExtra();
}


float Panificato::CalcoloPrezzo() const
{
    return this->Prodotto::CalcoloPrezzo() + temperatura/100.00 + (extra ? 1,50 : 0);
}

std::string Panificato::toString() const
{
    return this->Prodotto::toString() + "\n\tTemperatura: "+std::to_string(temperatura)+"\tExtra: "+std::to_string(extra);
}

bool Panificato::getExtra() const
{
    return extra;
}

void Panificato::setExtra(bool value)
{
    extra = value;
}

void Panificato::setTemperatura(int value)
{
    temperatura = value;
}

int Panificato::getTemperatura() const
{
    return temperatura;
}

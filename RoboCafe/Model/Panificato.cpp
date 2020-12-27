#include "Model/Panificato.h"

Panificato::Panificato(unsigned int id, std::string nome, float prezzo,unsigned int temp,unsigned int cal):
    Prodotto(id,nome, prezzo, cal),
    temperatura(temp){}

Panificato::~Panificato()= default;

Panificato::Panificato(const Panificato &other) = default;

Panificato &Panificato::operator=(const Panificato &other)=default;

bool Panificato::operator==(const Prodotto& other) const
{
    return Prodotto::operator==(other) && temperatura == static_cast<const Panificato&>(other).temperatura;
}

int Panificato::CalcoloEnergia() const
{
    return temperatura/20;
}

std::string Panificato::getDettagli() const
{
    return Prodotto::getDettagli();
}

float Panificato::CalcoloPrezzo() const
{
    return this->Prodotto::CalcoloPrezzo() + temperatura/100.00;
}

std::string Panificato::toString() const
{
    return this->Prodotto::toString() + "\n\tTemperatura: "+std::to_string(temperatura);
}

void Panificato::setTemperatura(int value)
{
    temperatura = value;
}

int Panificato::getTemperatura() const
{
    return temperatura;
}

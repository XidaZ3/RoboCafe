#include "Model/Panificato.h"

Panificato::Panificato(unsigned int id,std::string path, std::string nome, float prezzo,unsigned int temp,unsigned int cal,Dimensione dim):
    Prodotto(id,path,nome, prezzo, cal,dim),
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

std::string Panificato::toString() const
{
    return Prodotto::toString() + "\n\tTemperatura: "+std::to_string(getTemperatura());
}

float Panificato::CalcoloPrezzo() const
{
    return this->Prodotto::CalcoloPrezzo() + temperatura/100.00;
}

std::string Panificato::toJsonString() const
{
    std::string prec = Prodotto::toJsonString();
    std::string value = "\n\t\"panificato\": { \n\t\t\"temperatura\": "+std::to_string(temperatura)+"}";
    std::string ret = prec.insert(prec.size()-1,value);
    return ret;
}

void Panificato::setTemperatura(int value)
{
    temperatura = value;
}

int Panificato::getTemperatura() const
{
    return temperatura;
}

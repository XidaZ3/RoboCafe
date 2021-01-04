#include "Model/Panificato.h"

Panificato::Panificato(unsigned int id,std::string path, std::string nome, float prezzo,unsigned int temp,unsigned int cal,Dimensione dim):
    Prodotto(id,path,nome, prezzo, cal,dim),
    temperatura(temp){}

Panificato::Panificato():temperatura(){}

Panificato::~Panificato()= default;

Panificato::Panificato(const Panificato &other) = default;

Panificato &Panificato::operator=(const Panificato &other)=default;

bool Panificato::operator==(const Prodotto& other) const
{
    return Prodotto::operator==(other) && temperatura == static_cast<const Panificato&>(other).temperatura;
}

bool Panificato::operator!=(const Prodotto &other) const
{
    return !(Prodotto::operator==(other) && temperatura == static_cast<const Panificato&>(other).temperatura);
}

float Panificato::calcoloPrezzo() const
{
    return this->Prodotto::calcoloPrezzo() + (temperatura-180.00)/10;
}

int Panificato::calcoloEnergia() const
{
    return temperatura/20;
}

Vettore<std::string> Panificato::getDettagli() const
{
    Vettore<std::string> prec = Prodotto::getDettagli();
    prec.push_back("Temperatura: "+std::to_string(getTemperatura()));
    return prec;
}

std::string Panificato::toString() const
{
    return Prodotto::toString() + "\n\tTemperatura: "+std::to_string(getTemperatura());
}

void Panificato::read(const QJsonObject &json)
{
    Prodotto::read(json);
    temperatura = json["acqua"].toInt();
}

void Panificato::write(QJsonObject &json) const
{
    Prodotto::write(json);
    QJsonObject panificato;
    panificato["temperatura"] = static_cast<int>(temperatura);
    json["panificato"] = panificato;
}

void Panificato::setTemperatura(int value)
{
    temperatura = value;
}

int Panificato::getTemperatura() const
{
    return temperatura;
}

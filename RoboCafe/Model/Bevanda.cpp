#include "Model/Bevanda.h"

Bevanda::Bevanda(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal,Dimensione dim, bool gh):
    Prodotto(id,path, nome, prezzo, cal, dim), acqua(ac),ghiaccio(gh){}

Bevanda::Bevanda():acqua(),ghiaccio(){}

Bevanda::Bevanda(const Bevanda &other)=default;

Bevanda::~Bevanda()=default;

Bevanda &Bevanda::operator=(const Bevanda &other)=default;

bool Bevanda::operator==(const Bevanda &other) const
{
    return Prodotto::operator==(other) && acqua == static_cast<const Bevanda&>(other).acqua && ghiaccio == static_cast<const Bevanda&>(other).ghiaccio;
}

bool Bevanda::operator!=(const Bevanda &other) const
{
    return !(Prodotto::operator==(other) && acqua == static_cast<const Bevanda&>(other).acqua && ghiaccio == static_cast<const Bevanda&>(other).ghiaccio);
}

float Bevanda::calcoloPrezzo() const
{
    return this->Prodotto::calcoloPrezzo();
}

int Bevanda::calcoloEnergia() const
{
    return (acqua)/30;
}

Vettore<std::string> Bevanda::getDettagli() const
{
    Vettore<std::string> prec = Prodotto::getDettagli();
    if(ghiaccio)
        prec.push_back("Ghiaccio");
    return prec;
}

std::string Bevanda::toString() const
{
    return Prodotto::toString()+
            "\n\tAcqua: "+std::to_string(getAcqua())+"\tGhiaccio: "+(ghiaccio? "Si":"No");
}

void Bevanda::read(const QJsonObject &json)
{
    Prodotto::read(json);
    acqua = json["acqua"].toDouble();
    ghiaccio = json["ghiaccio"].toBool();
}

void Bevanda::write(QJsonObject &json) const
{
    Prodotto::write(json);
    QJsonObject bevanda;
    bevanda["acqua"] = acqua;
    bevanda["ghiaccio"] = ghiaccio;
    json["bevanda"] = bevanda;
}


float Bevanda::getAcqua() const
{
    return acqua;
}

void Bevanda::setAcqua(float value)
{
    acqua = value;
}

bool Bevanda::getGhiaccio() const
{
    return ghiaccio;
}

void Bevanda::setGhiaccio(bool value)
{
    ghiaccio = value;
}

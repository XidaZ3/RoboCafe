#include "Model/Prodotto.h"
#include <string>
#include <utility>
#include <typeinfo>

Prodotto::Prodotto(unsigned int id,std::string pth, std::string nome, float prezzo, unsigned int cal,Dimensione dim):
    idProdotto(id), calorie(cal), nomeProdotto(nome),path(pth), prezzoBase(prezzo), dimensione(dim) {}

Prodotto::Prodotto():idProdotto(),calorie(),nomeProdotto(),path(),prezzoBase(),dimensione() {}

Prodotto::~Prodotto() = default;

Prodotto &Prodotto::operator=(const Prodotto &other)=default;

bool Prodotto::operator==(const Prodotto &other) const
{
    return typeid (*this) == typeid (other) && idProdotto==other.idProdotto && path == other.path && nomeProdotto== other.nomeProdotto
            && calorie == other.calorie && prezzoBase == other.prezzoBase
            && dimensione == other.dimensione;
}

Prodotto::Prodotto(const Prodotto &other) = default;

float Prodotto::calcoloPrezzo() const
{
    return prezzoBase * (static_cast<int>(dimensione)+1);
}

Vettore<std::string> Prodotto::getDettagli() const
{
    Vettore<std::string> dettagli;
    dettagli.push_back(dimToString());
    return dettagli;
}

std::string Prodotto::toString() const
{
    return "IdProdotto: "+std::to_string(getIdProdotto())+"\tPath: "+getPath()+"\tNomeProdotto: "+getNomeProdotto()+"\tPrezzo: "+std::to_string(getPrezzoBase())+
            "\tCalorie: "+std::to_string(getCalorie())+"\tDimensione: "+dimToString();
}

std::string Prodotto::dimToString() const
{
    std::string result ="";
    switch (dimensione) {
        case Dimensione::Piccolo: result = "Piccolo";break;
        case Dimensione::Medio: result = "Medio";break;
        case Dimensione::Grande: result = "Grande";break;
    }
    return result;
}

void Prodotto::read(const QJsonObject &json)
{
    idProdotto = json["idProdotto"].toInt();
    path = json["path"].toString().toStdString();
    nomeProdotto=json["nomeProdotto"].toString().toStdString();
    prezzoBase = json["prezzo"].toDouble();
    calorie = json["calorie"].toInt();
    dimensione = (json["dimensione"].toInt() == 1 ? Dimensione::Piccolo : (json["dimensione"].toInt() == 2 ? Dimensione::Medio : Dimensione::Grande));
}

void Prodotto::write(QJsonObject &json) const
{
    json["idProdotto"] = static_cast<int>(getIdProdotto()); // costruttore di QJsonValue non accetta unsigned int, solo int
    json["path"] = QString::fromStdString(path);
    json["nomeProdotto"] = QString::fromStdString(nomeProdotto);
    json["prezzo"] = prezzoBase;
    json["calorie"] = static_cast<int>(calorie);
    json["dimensione"] = static_cast<int>(dimensione);
}

unsigned int Prodotto::getCalorie() const
{
    return calorie;
}

unsigned int Prodotto::getIdProdotto() const
{
    return idProdotto;
}

std::string Prodotto::getNomeProdotto() const
{
    return nomeProdotto;
}

float Prodotto::getPrezzoBase() const
{
    return prezzoBase;
}

Dimensione Prodotto::getDimensione() const
{
    return dimensione;
}

void Prodotto::setDimensione(const Dimensione &value)
{
    dimensione = value;
}

std::string Prodotto::getPath() const
{
    return path;
}

#include "Model/Prodotto.h"
#include <string>
#include <utility>
#include <typeinfo>

Dimensione Prodotto::getDimensione() const
{
    return dimensione;
}

void Prodotto::setDimensione(const Dimensione &value)
{
    dimensione = value;
}

Prodotto::Prodotto(unsigned int id,std::string pth, std::string nome, float prezzo, unsigned int cal,Dimensione dim):
    id_prodotto(id), calorie(cal), nome_prodotto(nome),path(pth), prezzo_base(prezzo), dimensione(dim) {}

Prodotto::Prodotto():id_prodotto(),calorie(),nome_prodotto(),path(),prezzo_base(),dimensione() {}

std::string Prodotto::getPath() const
{
    return path;
}

bool Prodotto::operator==(const Prodotto &other) const
{
    return typeid (*this) == typeid (other) && id_prodotto==other.id_prodotto && path == other.path && nome_prodotto== other.nome_prodotto
            && calorie == other.calorie && prezzo_base == other.prezzo_base
            && dimensione == other.dimensione;
}

Prodotto::~Prodotto() = default;

Prodotto::Prodotto(const Prodotto &other) = default;

Prodotto &Prodotto::operator=(const Prodotto &other)=default;

float Prodotto::CalcoloPrezzo() const
{
    return prezzo_base * (static_cast<int>(dimensione)+1);
}

std::string Prodotto::getDettagli() const
{
    return dimToString()+",";
}

std::string Prodotto::toString() const
{
    return "IdProdotto: "+std::to_string(getId_prodotto())+"\tPath: "+getPath()+"\tNomeProdotto: "+getNome_prodotto()+"\tPrezzo: "+std::to_string(getPrezzo_base())+
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
    id_prodotto = json["idProdotto"].toInt();
    path = json["path"].toString().toStdString();
    nome_prodotto=json["nomeProdotto"].toString().toStdString();
    prezzo_base = json["prezzo"].toDouble();
    calorie = json["calorie"].toInt();
    dimensione = (json["dimensione"].toInt() == 1 ? Dimensione::Piccolo : (json["dimensione"].toInt() == 2 ? Dimensione::Medio : Dimensione::Grande));
}

void Prodotto::write(QJsonObject &json) const
{
    json["idProdotto"] = static_cast<int>(getId_prodotto()); // costruttore di QJsonValue non accetta unsigned int, solo int
    json["path"] = QString::fromStdString(path);
    json["nomeProdotto"] = QString::fromStdString(nome_prodotto);
    json["prezzo"] = prezzo_base;
    json["calorie"] = static_cast<int>(calorie);
    json["dimensione"] = static_cast<int>(dimensione);
}

unsigned int Prodotto::getCalorie() const
{
    return calorie;
}

unsigned int Prodotto::getId_prodotto() const
{
    return id_prodotto;
}

std::string Prodotto::getNome_prodotto() const
{
    return nome_prodotto;
}

float Prodotto::getPrezzo_base() const
{
    return prezzo_base;
}

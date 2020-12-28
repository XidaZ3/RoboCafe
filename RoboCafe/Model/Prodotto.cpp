#include "Model/Prodotto.h"
#include <string>
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

std::string Prodotto::toJsonString() const
{
    std::string res ="\n\"prodotto\": {\n\t\"idProdotto\": \""+std::to_string(getId_prodotto())+"\",\n\t\"path\": \""+getPath()+"\",\n\t\"nomeProdotto\": \""+getNome_prodotto()+"\",\n\t\"prezzo\": "+std::to_string(getPrezzo_base())+",\n\t\"calorie\": "+std::to_string(getCalorie())
            +",\n\t\"dimensione\": "+std::to_string(static_cast<int>(getDimensione()))+"}";
    return res;

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

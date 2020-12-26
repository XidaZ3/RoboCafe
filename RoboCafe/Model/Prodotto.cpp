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

Prodotto::Prodotto(unsigned int id, unsigned int quantita, std::string nome, float prezzo, unsigned int cal,Dimensione dim):
    id_prodotto(id), quantita_rimasta(quantita), calorie(cal), nome_prodotto(nome), prezzo_base(prezzo), dimensione(dim) {}

bool Prodotto::operator==(const Prodotto &other) const
{
    return typeid (*this) == typeid (other) && id_prodotto==other.id_prodotto && nome_prodotto== other.nome_prodotto
            && calorie == other.calorie && quantita_rimasta== other.quantita_rimasta && prezzo_base == other.prezzo_base
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
    std::string res ="\n\"Prodotto\": {\n\t\"nomeProdotto\": \""+getNome_prodotto()+"\",\n\t\"calorie\": "+std::to_string(getCalorie())
            +",\n\t\"dimensione\": "+std::to_string(static_cast<int>(getDimensione()))+",";
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

unsigned int Prodotto::getQuantita_rimasta() const
{
    return quantita_rimasta;
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

#include "Prodotto.h"
#include <string>

Prodotto::Prodotto(unsigned int id, unsigned int quantita, std::string nome, float prezzo, unsigned int cal):
    id_prodotto(id), quantita_rimasta(quantita), calorie(cal), nome_prodotto(nome), prezzo_base(prezzo) {}

bool Prodotto::operator==(const Prodotto &other) const
{
    return id_prodotto == other.getId_prodotto() && quantita_rimasta == other.getQuantita_rimasta() && nome_prodotto == other.getNome_prodotto() &&
           prezzo_base == other.getPrezzo_base() && calorie ==other.getCalorie();
}

Prodotto::~Prodotto() = default;

Prodotto::Prodotto(const Prodotto &other) = default;

Prodotto &Prodotto::operator=(const Prodotto &other)=default;

float Prodotto::CalcoloPrezzo() const
{
    return prezzo_base;
}

std::string Prodotto::toString() const
{
    std::string res ="Nome: "+getNome_prodotto()+"\tQuantità rimasta: "+std::to_string(getQuantita_rimasta())+"\tCalorie: "+std::to_string(getCalorie());
    return res;
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

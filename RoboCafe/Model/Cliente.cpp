#include "Model/Cliente.h"
#include <typeinfo>
float Cliente::getCredito() const
{
    return credito;
}

string Cliente::getNome() const
{
    return nome;
}

string Cliente::getCognome() const
{
    return cognome;
}


Cliente::~Cliente(){}

string Cliente::toString() const{
    return "Nome:"+getNome()+" Cognome:"+getCognome()+" Credito rimanente:"+std::to_string(getCredito());
}

int Cliente::getCodice() const
{
    return codice;
}

Cliente::Cliente(int cod, float cre, string nom, string cog):codice(cod),credito(cre),nome(nom), cognome(cog){}

void Cliente::addCredito(float s)
{
    credito+=s;
}

void Cliente::subCredito(float s)
{
    if(getCredito()-s<0)
        throw CreditoInsufficiente;
    else
        credito-=s;
}

float Cliente::Pagamento(float s)
{
    subCredito(s);
    return s;
}

void Cliente::Ricarica(float s)
{
    addCredito(s);
}

bool Cliente::operator==(const Cliente &c) const
{
    return typeid(*this) == typeid(c) && codice == c.codice && nome == c.nome && cognome == c.cognome && credito == c.credito;
}

bool Cliente::operator!=(const Cliente &c) const
{
    return typeid(*this) != typeid(c) || codice != c.codice || nome != c.nome || cognome != c.cognome || credito != c.credito;
}

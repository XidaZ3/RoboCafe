#include "Cliente.h"

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

Cliente::Cliente(int cod, float cre, string nom, string cog):codice(cod),credito(cre),nome(nom), cognome(cog){}

Cliente::~Cliente(){}

string Cliente::toString() const{
    return "Nome:"+getNome()+" Cognome:"+getCognome()+" Credito rimanente:"+std::to_string(getCredito());
}


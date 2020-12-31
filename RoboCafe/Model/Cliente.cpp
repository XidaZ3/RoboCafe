#include "Model/Cliente.h"

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
    return "Id:"+ std::to_string(getId()) + " Nome:"+getNome()+" Cognome:"+getCognome()+" Credito rimanente:"+std::to_string(getCredito());
}

QJsonObject Cliente::toQJsonObject(string &tipo) const
{
    QJsonObject dati;
   // cliente.begin();
    dati.insert("id",id);
    dati.insert("nome",QString::fromStdString(nome));
    dati.insert("cognome",QString::fromStdString(cognome));
    dati.insert("credito",credito);
    tipo = "cliente";
    return dati;
}


int Cliente::getId() const
{
    return id;
}

Cliente::Cliente(int cod, string nom, string cog, float cre):id(cod),nome(nom), cognome(cog),credito(cre){}

void Cliente::addCredito(float s)
{
    credito+=s;
}

void Cliente::subCredito(float s)
{
    if(getCredito()-s<0)
        throw EccezioniCliente::CreditoInsufficiente;
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
    return typeid(*this) == typeid(c) && id == c.id && nome == c.nome && cognome == c.cognome && credito == c.credito;
}

bool Cliente::operator!=(const Cliente &c) const
{
    return typeid(*this) != typeid(c) || id != c.id || nome != c.nome || cognome != c.cognome || credito != c.credito;
}

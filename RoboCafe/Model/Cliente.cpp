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

QJsonObject Cliente::toQJsonObject() const
{
    QJsonObject dati,cliente;
    dati.insert("id",id);
    dati.insert("nome",QString::fromStdString(nome));
    dati.insert("cognome",QString::fromStdString(cognome));
    dati.insert("credito",credito);
    cliente.insert("cliente",dati);
    return cliente;
}

void Cliente::fromQJsonObject(const QJsonObject& dati)
{
    if(dati.contains("cliente") && dati["cliente"].isObject())
    {
        QJsonObject fields = dati["cliente"].toObject();

        if(fields.contains("id") && fields["id"].isDouble())
            id = fields["id"].toInt();
        if(fields.contains("nome") && fields["nome"].isString())
            nome = fields.value("nome").toString().toStdString();
        if(fields.contains("cognome") && fields["cognome"].isString())
            cognome = fields["cognome"].toString().toStdString();
        if(fields.contains("credito") && fields["credito"].isDouble())
            credito = fields["credito"].toDouble();
    }
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

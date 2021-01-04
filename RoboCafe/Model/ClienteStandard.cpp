#include "Model/ClienteStandard.h"

ClienteStandard::ClienteStandard(int cod, string nom, string cog, float cre):Cliente(cod,nom,cog,cre){}

ClienteStandard::~ClienteStandard(){}

Cliente* ClienteStandard::clone() const
{
    return new ClienteStandard(*this);
}

QJsonObject ClienteStandard::toQJsonObject() const
{
    QJsonObject cliente = Cliente::toQJsonObject(),standard;
    cliente.insert("clienteStandard",standard);
    return cliente;
}


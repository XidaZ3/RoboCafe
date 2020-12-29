#include "Model/ClienteStandard.h"

ClienteStandard::ClienteStandard(int cod, string nom, string cog, float cre):Cliente(cod,nom,cog,cre){}

ClienteStandard::~ClienteStandard(){}

Cliente* ClienteStandard::clone() const
{
    return new ClienteStandard(*this);
}

QJsonObject ClienteStandard::toQJsonObject(std::string &tipo) const
{
    QJsonObject c=Cliente::toQJsonObject(tipo);
    tipo="clienteStandard";
    return c;
}

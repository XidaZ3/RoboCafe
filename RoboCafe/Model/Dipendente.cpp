#include "Model/Dipendente.h"
const float Dipendente::sconto = 0.8f;

Dipendente::Dipendente(int cod, string nom, string cog, float cre):Cliente(cod,nom,cog,cre){}

Dipendente::~Dipendente(){}

float Dipendente::Pagamento(float s){
    //sconto del 20%
    s=s*sconto;
    return Cliente::Pagamento(s);
}

Cliente* Dipendente::clone() const
{
    return new Dipendente(*this);
}

QJsonObject Dipendente::toQJsonObject(string &tipo) const
{
    QJsonObject c=Cliente::toQJsonObject(tipo);
    tipo="dipendente";
    return c;
}

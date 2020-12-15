#include "ClientePlus.h"

int ClientePlus::getPunti() const
{
    return punti;
}

int ClientePlus::getLivello() const
{
    return livello;
}

ClientePlus::ClientePlus(int pun,int liv):punti(pun),livello(liv){}

ClientePlus::~ClientePlus(){}

string ClientePlus::toString() const{
    return Cliente::toString()+" Livello:"+std::to_string(getLivello())+" Punti:"+std::to_string(getPunti());
}

float ClientePlus::Pagamento(const float &s) const{

}

void convertiPuntiLivello()
{

}

void convertiPuntiCredito()
{

}

bool upgradeLivello()
{

}

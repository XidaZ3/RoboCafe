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

ClientePlus::ClientePlus(const Cliente &c,int pun,int liv):Cliente(c),punti(pun),livello(liv){}

Cliente* ClientePlus::clone() const
{
    return new ClientePlus(*this);
}

ClientePlus::~ClientePlus(){}

string ClientePlus::toString() const{
    return Cliente::toString()+" Livello:"+std::to_string(getLivello())+" Punti:"+std::to_string(getPunti());
}

void ClientePlus::addPunti(int p){
    punti+=p;
}

void ClientePlus::subPunti(int p){
    punti-=p;
}

void ClientePlus::levelUp(){
    livello++;
}

float ClientePlus::Pagamento(float s){
    //sconto in base al livello del 5%-30%max
    s=s-(s*livello*0.05);
    addPunti(s);
    return Cliente::Pagamento(s);
}

void ClientePlus::convertiPuntiCredito()
{
    addCredito(punti/10);
    subPunti(punti);
}

void ClientePlus::upgradeLivello()
{
    if(punti>100 && livello<6)
        levelUp();
    else if(livello>=3)
        throw LivelloMassimo;
    else if(punti<100)
        throw PuntiInsufficienti;
}

void ClientePlus::Ricarica(float s)
{
    addPunti(s);
    Cliente::Ricarica(s);
}
bool ClientePlus::operator==(const Cliente &c) const
{
    return Cliente::operator==(c) && punti==static_cast<const ClientePlus&>(c).punti && livello==static_cast<const ClientePlus&>(c).livello;
}

bool ClientePlus::operator!=(const Cliente &c) const
{
    return Cliente::operator!=(c) || punti!=static_cast<const ClientePlus&>(c).punti || livello!=static_cast<const ClientePlus&>(c).livello;
}

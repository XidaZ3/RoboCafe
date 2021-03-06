#include "Model/ClientePlus.h"

int ClientePlus::getPunti() const
{
    return punti;
}

int ClientePlus::getLivello() const
{
    return livello;
}

ClientePlus::ClientePlus(int cod, string nom, string cog, float cre,int pun,int liv):Cliente(cod,nom,cog,cre),punti(pun),livello(liv){}

ClientePlus::ClientePlus(const Cliente &c,int pun,int liv):Cliente(c),punti(pun),livello(liv){}

Cliente* ClientePlus::clone() const
{
    return new ClientePlus(*this);
}

ClientePlus::~ClientePlus(){}

string ClientePlus::toString() const{
    return Cliente::toString()+" Livello:"+std::to_string(getLivello())+" Punti:"+std::to_string(getPunti());
}

QJsonObject ClientePlus::toQJsonObject() const
{
    QJsonObject cliente = Cliente::toQJsonObject(), plus;
    plus.insert("punti",punti);
    plus.insert("livello",livello);
    cliente.insert("clientePlus",plus);
    return cliente;
}

void ClientePlus::fromQJsonObject(const QJsonObject &dati)
{
    Cliente::fromQJsonObject(dati);
    if(dati.contains("clientePlus") && dati["clientePlus"].isObject())
    {
        QJsonObject fields = dati["clientePlus"].toObject();

        if(fields.contains("punti") && fields["punti"].isDouble())
            punti = fields["punti"].toInt();
        if(fields.contains("livello") && fields["livello"].isDouble())
            livello= fields["livello"].toDouble();
    }
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
    if(punti/10>=1)
    {
        addCredito(punti/10);
        subPunti(punti);
    }else
        throw EccezioniCliente::PuntiInsufficienti;
}

void ClientePlus::upgradeLivello()
{
    if(punti>100 && livello<6)
    {
        levelUp();
        subPunti(100);
    }
    else if(livello>=6)
        throw EccezioniCliente::LivelloMassimo;
    else if(punti<100)
        throw EccezioniCliente::PuntiInsufficienti;
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

#ifndef CLIENTEPLUS_H
#define CLIENTEPLUS_H
#include "Model/Cliente.h"
#include "Model/ClienteStandard.h"

class ClientePlus:public Cliente
{
private:
    int punti;
    int livello;
public:
    ClientePlus(int id=0, string nom="NULL", string cog="NULL", float cre=0,int pun=0,int liv=1);
    ClientePlus(const Cliente &c,int pun=0,int liv=1);
    ~ClientePlus();
    Cliente* clone() const override;
    bool operator==(const Cliente &c) const override;
    bool operator!=(const Cliente &c) const override;

    float Pagamento(float s) override;
    void Ricarica(float s) override;
    void convertiPuntiCredito();
    void upgradeLivello();
    string toString() const override;
    QJsonObject toQJsonObject() const override;
    void fromQJsonObject(const QJsonObject& dati) override;

    int getPunti() const;
    int getLivello() const;
protected:

    void addPunti(int p);
    void subPunti(int p);
    void levelUp();
};

#endif // CLIENTEPLUS_H

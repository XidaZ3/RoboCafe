#ifndef CLIENTEPLUS_H
#define CLIENTEPLUS_H
#include "Cliente.h"

class ClientePlus:Cliente
{
private:
    int punti;
    int livello;
public:
    ClientePlus(int pun=0,int liv=0);
    ~ClientePlus() override;
    string toString() const override;
    void convertiPuntiLivello();
    void convertiPuntiCredito();
    bool upgradeLivello();
    float Pagamento(const float &s) const override;

    int getPunti() const;
    int getLivello() const;
};

#endif // CLIENTEPLUS_H

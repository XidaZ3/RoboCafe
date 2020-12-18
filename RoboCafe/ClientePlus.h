#ifndef CLIENTEPLUS_H
#define CLIENTEPLUS_H
#include "Cliente.h"

class ClientePlus:public Cliente
{
private:
    int punti;
    int livello;
public:


    ClientePlus(int pun=0,int liv=1);
    ~ClientePlus();
    string toString() const override;
    void convertiPuntiCredito();
    void upgradeLivello();
    float Pagamento(float s) override;
    void Ricarica(float s) override;

    int getPunti() const;
    int getLivello() const;
protected:
    enum EccezioneClientePlus
    {
        LivelloMassimo,
        PuntiInsufficienti
    };

    void addPunti(int p);
    void subPunti(int p);
    void levelUp();
};

#endif // CLIENTEPLUS_H

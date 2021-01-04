#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "Model/Cliente.h"

class Dipendente:public Cliente
{
public:
    Dipendente(int id=0, string nom="NULL", string cog="NULL", float cre=0);
    ~Dipendente();
    float Pagamento(float s) override;
    Cliente* clone() const override;
     QJsonObject toQJsonObject() const override;
     const static float sconto;
};

#endif // DIPENDENTE_H

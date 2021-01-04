#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "Model/Cliente.h"

class Dipendente:public Cliente
{
private:

public:
    const static float sconto;

    Dipendente(int id=0, string nom="NULL", string cog="NULL", float cre=0);
    ~Dipendente();
    Cliente* clone() const override;

    float Pagamento(float s) override;
    QJsonObject toQJsonObject() const override;
};

#endif // DIPENDENTE_H

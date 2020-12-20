#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "Cliente.h"

class Dipendente:public Cliente
{
private:
    const static float sconto;
public:
    Dipendente();
    ~Dipendente();
    float Pagamento(float s) override;
    Cliente* clone() const override;
};

#endif // DIPENDENTE_H

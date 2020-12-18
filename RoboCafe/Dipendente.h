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
    virtual float Pagamento(float s) override;
};

#endif // DIPENDENTE_H

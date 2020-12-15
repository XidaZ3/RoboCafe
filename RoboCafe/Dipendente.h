#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "Cliente.h"

class Dipendente:Cliente
{
private:
    const static float sconto;
public:
    Dipendente();
    virtual ~Dipendente();
    virtual float Pagamento(const float &s) const override;
};

#endif // DIPENDENTE_H

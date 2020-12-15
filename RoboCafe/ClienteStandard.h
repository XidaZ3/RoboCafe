#ifndef CLIENTESTANDARD_H
#define CLIENTESTANDARD_H
#include "Cliente.h"

class ClienteStandard:Cliente
{
public:
    ClienteStandard();
    ~ClienteStandard() override;
    virtual float Pagamento(const float &s) const override;
    void diventaPlus();
};

#endif // CLIENTESTANDARD_H

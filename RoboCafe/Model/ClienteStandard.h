#ifndef CLIENTESTANDARD_H
#define CLIENTESTANDARD_H
#include "Model/Cliente.h"

class ClienteStandard:public Cliente
{
public:
    ClienteStandard();
    ~ClienteStandard();
    Cliente* clone() const override;
};

#endif // CLIENTESTANDARD_H

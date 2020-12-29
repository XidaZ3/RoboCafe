#ifndef CLIENTESTANDARD_H
#define CLIENTESTANDARD_H
#include "Model/Cliente.h"

class ClienteStandard:public Cliente
{
public:
    ClienteStandard(int id=0, string nom="NULL", string cog="NULL", float cre=0);
    ~ClienteStandard();
    Cliente* clone() const override;
    QJsonObject toQJsonObject(string &tipo) const override;
};

#endif // CLIENTESTANDARD_H

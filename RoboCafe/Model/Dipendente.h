#ifndef DIPENDENTE_H
#define DIPENDENTE_H
#include "Model/Cliente.h"

class Dipendente:public Cliente
{
private:
    const static float sconto;
public:
    Dipendente(int cod=0, string nom="NULL", string cog="NULL", float cre=0);
    ~Dipendente();
    float Pagamento(float s) override;
    Cliente* clone() const override;
};

#endif // DIPENDENTE_H

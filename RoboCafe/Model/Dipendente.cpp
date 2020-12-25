#include "Model/Dipendente.h"
const float Dipendente::sconto = 0.8f;

Dipendente::Dipendente()
{

}

Dipendente::~Dipendente(){}

float Dipendente::Pagamento(float s){
    //sconto del 20%
    s=s*sconto;
    return Cliente::Pagamento(s);
}

Cliente* Dipendente::clone() const
{
    return new Dipendente(*this);
}

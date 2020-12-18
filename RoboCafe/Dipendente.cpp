#include "Dipendente.h"

Dipendente::Dipendente()
{

}

Dipendente::~Dipendente(){}

float Dipendente::Pagamento(float s){
    //sconto del 20%
    s=s*sconto;
    return Cliente::Pagamento(s);
}

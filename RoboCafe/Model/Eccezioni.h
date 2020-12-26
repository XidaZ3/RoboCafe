#ifndef ECCEZIONI_H
#define ECCEZIONI_H

class Eccezioni{
public:
    static const int CreditoInsufficiente= 1;
    static const int ProdottoInesistente=2;
    static const int ClienteNonPlus=3;
    static const int ClienteNonStandard=4;
 };

class EccezioniPreparazione : public Eccezioni {
public:
    static const int AcquaInsufficiente = 10;
    static const int CaffeInsufficiente = 11;
    static const int ImpastoPizzaInsufficiente= 12;
    static const int FiltriTeInsufficienti = 13;
    static const int LitriLatteInsufficiente = 14;
};


#endif // ECCEZIONI_H

#ifndef ECCEZIONI_H
#define ECCEZIONI_H

class EccezioniCliente{
public:
    static const int CreditoInsufficiente= 1;
    static const int ClienteInesistente=2;
    static const int ClienteNonPlus=3;
    static const int ClienteNonStandard=4;
    static const int LivelloMassimo=5;
    static const int PuntiInsufficienti = 6;
 };

class EccezioniPreparazione{
public:
    static const int AcquaInsufficiente = 10;
    static const int CaffeInsufficiente = 11;
    static const int ImpastoPizzaInsufficiente= 12;
    static const int FiltriTeInsufficienti = 13;
    static const int LitriLatteInsufficiente = 14;
    static const int ProdottoInesistente = 15;
};

class EccezioniModel{
public:
    static const int CreditoNonPrelevabile =50;
    static const int CreditoNegativo =51;
};

#endif // ECCEZIONI_H

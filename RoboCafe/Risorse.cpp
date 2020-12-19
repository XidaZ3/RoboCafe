#include "Risorse.h"
#include "Eccezioni.h"

const float Risorse::limiteLitriAcqua = 10;
const float Risorse::limiteLitriLatte = 5;
const int Risorse::limiteCialdeCaffe = 100;
const int Risorse::limiteImpastiPizze = 50;
const int Risorse::limiteFiltriTe = 100;


Risorse::Risorse()
{

}

void Risorse::subAcqua(float s)
{
    if(s <= litriAcqua) litriAcqua -= s;
    else throw EccezioniPreparazione::AcquaInsufficiente;
}

void Risorse::subCaffe(int s)
{
    if(s <= cialdeCaffe) cialdeCaffe -= s;
    else throw EccezioniPreparazione::CaffeInsufficiente;
}

void Risorse::subTe(int s)
{
    if(s <= filtriTe) filtriTe -= s;
    else throw EccezioniPreparazione::FiltriTeInsufficienti;
}

void Risorse::subLatte(float s)
{
    if(s <= litriLatte) litriLatte -= s;
    else throw EccezioniPreparazione::LitriLatteInsufficiente;
}

void Risorse::subPizza(int s)
{
    if(s <= impastiPizze) impastiPizze -= s;
    else throw EccezioniPreparazione::ImpastoPizzaInsufficiente;
}

void Risorse::rifornituraAcqua(){
    litriAcqua = limiteLitriAcqua;
}
void Risorse::rifornituraCaffe(){
    cialdeCaffe = limiteCialdeCaffe;
}
void Risorse::rifornituraLatte(){
    litriLatte = limiteLitriLatte;
}
void Risorse::rifornituraTe(){
    filtriTe = limiteFiltriTe;
}
void Risorse::rifornituraPizza(){
    impastiPizze = limiteImpastiPizze;
}


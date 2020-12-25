#include "Model/Risorse.h"
#include <iostream>
using namespace std;
const float Risorse::limiteLitriAcqua = 10;
const float Risorse::limiteLitriLatte = 5;
const int Risorse::limiteCialdeCaffe = 100;
const int Risorse::limiteImpastiPizze = 50;
const int Risorse::limiteFiltriTe = 100;


int Risorse::getTemperatura() const
{
    return temperatura;
}

int Risorse::getImpastiPizze() const
{
    return impastiPizze;
}

int Risorse::getCialdeCaffe() const
{
    return cialdeCaffe;
}

int Risorse::getFiltriTe() const
{
    return filtriTe;
}

float Risorse::getLitriAcqua() const
{
    return litriAcqua;
}

float Risorse::getLitriLatte() const
{
    return litriLatte;
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

Risorse::Risorse(int tem, int imp, int cia, int fil, float acq, float lat):temperatura(tem),impastiPizze(imp),cialdeCaffe(cia), filtriTe(fil),litriAcqua(acq),litriLatte(lat){}

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


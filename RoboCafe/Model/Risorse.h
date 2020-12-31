#ifndef RISORSE_H
#define RISORSE_H
#include "Model/Eccezioni.h"
#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <iostream>
class Risorse
{
private:
    int temperatura,impastiPizze,cialdeCaffe, filtriTe;
    float litriAcqua,litriLatte;

    static const float limiteLitriAcqua, limiteLitriLatte;
    static const int limiteImpastiPizze, limiteCialdeCaffe, limiteFiltriTe;

public:
    Risorse(int tem = 0, int imp = 20, int cia = 20, int fil = 20, float acq = 5, float lat = 2);
    virtual ~Risorse();

    void setTemperatura();

    void rifornituraAcqua();
    void rifornituraCaffe();
    void rifornituraTe();
    void rifornituraLatte();
    void rifornituraPizza();

    void subAcqua(float s);
    void subCaffe(int s);
    void subTe(int s);
    void subLatte(float s);
    void subPizza(int s);

    int getTemperatura() const;
    int getImpastiPizze() const;
    int getCialdeCaffe() const;
    int getFiltriTe() const;
    float getLitriAcqua() const;
    float getLitriLatte() const;

    void readFromFile();
    void writeToFile() const;
};



#endif // RISORSE_H

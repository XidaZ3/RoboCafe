#include "Model/Risorse.h"

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

void Risorse::readFromFile()
{
    QString path("../RoboCafe/Controller/Files/risorse.json");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Impossibile aprire il file");
        return;
    }

    QByteArray byteArr = file.readAll();
    QJsonDocument doc (QJsonDocument::fromJson(byteArr));
    QJsonObject model = doc.object();
    if(model.contains("impastiPizze") && model["impastiPizze"].isDouble())
        impastiPizze=model["impastiPizze"].toInt();
    if(model.contains("cialdeCaffe") && model["cialdeCaffe"].isDouble())
        cialdeCaffe=model["cialdeCaffe"].toInt();
    if(model.contains("filtriTe") && model["filtriTe"].isDouble())
        filtriTe=model["filtriTe"].toInt();
    if(model.contains("litriAcqua") && model["litriAcqua"].isDouble())
        litriAcqua=model["litriAcqua"].toDouble();
    if(model.contains("litriLatte") && model["litriLatte"].isDouble())
        litriLatte=model["litriLatte"].toInt();

    file.close();
}

void Risorse::writeToFile() const
{
    QJsonObject model;
    model.insert("impastiPizze",impastiPizze);
    model.insert("cialdeCaffe",cialdeCaffe);
    model.insert("filtriTe",filtriTe);
    model.insert("litriAcqua",litriAcqua);
    model.insert("litriLatte",litriLatte);
    QJsonDocument doc(model);
    QByteArray bytes = doc.toJson();
    QString path("../RoboCafe/Controller/Files/risorse.json");
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
        std::cout << "Fallito" << std::endl;
    else
    {
        QTextStream stream(&file);
        stream.setCodec("utf-8");
        stream<<bytes;
        file.close();
    }
}

Risorse::Risorse(int tem, int imp, int cia, int fil, float acq, float lat):temperatura(tem),impastiPizze(imp),cialdeCaffe(cia), filtriTe(fil),litriAcqua(acq),litriLatte(lat){}

Risorse::~Risorse(){}

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


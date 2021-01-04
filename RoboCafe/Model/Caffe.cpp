#include "Model/Caffe.h"
#include <string>

Caffe::Caffe(unsigned int id,std::string path, std::string nome, float prezzo,float ac,unsigned int cal,Dimensione dim,
             bool gh,float l, int caf, bool ca, bool cara):
    Bevanda(id,path, nome, prezzo,ac, cal, dim, gh),latte(l),cialdeCaffe(caf), cacao(ca), caramello(cara){}

Caffe::Caffe():latte(),cialdeCaffe(),cacao(),caramello(){}

Caffe::Caffe(const Caffe &other)=default;

Caffe::~Caffe()=default;

Caffe &Caffe::operator=(const Caffe &other)=default;

bool Caffe::operator==(const Caffe &other) const
{
    return Bevanda::operator==(other)&& latte==static_cast<const Caffe&>(other).latte && cialdeCaffe == static_cast<const Caffe&>(other).cialdeCaffe && cacao==static_cast<const Caffe&>(other).cacao && caramello == static_cast<const Caffe&>(other).caramello;
}

bool Caffe::operator!=(const Caffe &other) const
{
    return !(Bevanda::operator==(other)&& latte==static_cast<const Caffe&>(other).latte && cialdeCaffe == static_cast<const Caffe&>(other).cialdeCaffe && cacao==static_cast<const Caffe&>(other).cacao && caramello == static_cast<const Caffe&>(other).caramello);
}

Caffe *Caffe::clone() const
{
    return new Caffe(*this);
}

void Caffe::preparazione(Risorse &Risorse) const
{
    switch (getDimensione()) {
        case Dimensione::Piccolo: Risorse.subAcqua(getAcqua()*0.7); Risorse.subCaffe(getCialdeCaffe()); Risorse.subLatte(getLatte());break;
        case Dimensione::Medio: Risorse.subAcqua(getAcqua()); Risorse.subCaffe(getCialdeCaffe()); Risorse.subLatte(getLatte());break;
        case Dimensione::Grande: Risorse.subAcqua(getAcqua()*1.2); Risorse.subCaffe(getCialdeCaffe()); Risorse.subLatte(getLatte());break;
        default:;
    }
}

float Caffe::calcoloPrezzo() const
{
    return this->Bevanda::calcoloPrezzo() +(latte/100)+cialdeCaffe+ (cacao && caramello ? 1 : 0);
}

int Caffe::calcoloEnergia() const
{
    return Bevanda::calcoloEnergia() + (cacao && caramello ? 5 : 0);
}

Vettore<std::string> Caffe::getDettagli() const
{
    Vettore<std::string> prec = Bevanda::getDettagli();
    prec.push_back("Cialde: x"+std::to_string(cialdeCaffe));
    if(cacao)
        prec.push_back("Cacao");
    if(caramello)
        prec.push_back("Caramello");
    return prec;
}

std::string Caffe::toString() const
{
    return Bevanda::toString() + "\n\t\tCialdeCaffe: x"+std::to_string(getCialdeCaffe())+"\tLatte: "+std::to_string(getLatte())+"\tCacao: "+(cacao ? "Si" : "No")+"\tCaramello: "+ (caramello ? "Si" : "No");
}

void Caffe::read(const QJsonObject &json)
{
    Bevanda::read(json);
    cialdeCaffe = json["cialdeCaffe"].toInt();
    latte = json["latte"].toDouble();
    cacao = json["cacao"].toBool();
    caramello =json["caramello"].toBool();
}

void Caffe::write(QJsonObject &json) const
{
    Bevanda::write(json);
    QJsonObject caffe;
    caffe["cialdeCaffe"] = cialdeCaffe;
    caffe["latte"] = latte;
    caffe["cacao"] = cacao;
    caffe["caramello"] = caramello;
    json["caffe"]=caffe;

}

bool Caffe::getCaramello() const
{
    return caramello;
}

void Caffe::setCaramello(bool value)
{
    caramello = value;
}

bool Caffe::getCacao() const
{
    return cacao;
}

void Caffe::setCacao(bool value)
{
    cacao = value;
}


float Caffe::getLatte() const
{
    return latte;
}

void Caffe::setLatte(float value)
{
    latte = value;
}

int Caffe::getCialdeCaffe() const
{
    return cialdeCaffe;
}

void Caffe::setCialdeCaffe(int value)
{
    cialdeCaffe = value;
}

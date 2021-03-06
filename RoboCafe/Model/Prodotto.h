#ifndef PRODOTTO_H
#define PRODOTTO_H
#include <iostream>
#include <string>
#include "Model/Risorse.h"
#include "Model/Vettore.h"
#include <QJsonObject>

enum class Dimensione {Piccolo, Medio, Grande};
class Prodotto
{
    private:
        unsigned int idProdotto, calorie;
        std::string nomeProdotto,path;
        float prezzoBase;
        Dimensione dimensione;
    public:
        Prodotto(unsigned int id,std::string path, std::string nome, float prezzo, unsigned int calorie = -1, Dimensione dim = Dimensione::Medio);
        Prodotto();
        virtual ~Prodotto();
        Prodotto(const Prodotto& other);
        virtual Prodotto& operator=(const Prodotto& other);
        virtual bool operator==(const Prodotto& other)const;
        virtual bool operator!=(const Prodotto& other)const;
        virtual Prodotto* clone() const = 0;

        virtual void preparazione(Risorse& Risorse)const = 0;
        virtual float calcoloPrezzo() const;
        virtual int calcoloEnergia()const = 0;
        virtual Vettore<std::string> getDettagli() const;
        virtual std::string toString() const;
        std::string dimToString() const;

        virtual void read(const QJsonObject& json);
        virtual void write(QJsonObject& json) const;

        unsigned int getCalorie() const;
        unsigned int getIdProdotto() const;
        std::string getNomeProdotto() const;
        float getPrezzoBase() const;
        Dimensione getDimensione() const;
        void setDimensione(const Dimensione &value);
        std::string getPath() const;
};

#endif // PRODOTTO_H

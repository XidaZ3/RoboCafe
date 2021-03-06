#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
#include <QJsonObject>
#include <Model/Eccezioni.h>
using std::string;

class Cliente
{
private:
    int id;
    string nome;
    string cognome;
    float credito;

public:
    Cliente(int id=0, string nom="NULL", string cog="NULL", float cre=0);
    virtual ~Cliente()=0;
    virtual bool operator==(const Cliente &c) const;
    virtual bool operator!=(const Cliente &c) const;
    virtual Cliente* clone() const =0;

    virtual float Pagamento(float s);
    virtual void Ricarica(float s);
    virtual string toString() const;
    virtual QJsonObject toQJsonObject() const;
    virtual void fromQJsonObject(const QJsonObject& dati);

    float getCredito() const;
    string getNome() const;
    string getCognome() const;
    int getId() const;

protected:
    void addCredito(float s);
    void subCredito(float s);
};

#endif // CLIENTE_H

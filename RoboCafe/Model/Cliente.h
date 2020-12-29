#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
#include <QJsonObject>
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
    virtual string toString() const;
    virtual QJsonObject toQJsonObject(string &tipo) const;
    virtual float Pagamento(float s);
    virtual void Ricarica(float s);
    virtual bool operator==(const Cliente &c) const;
    virtual bool operator!=(const Cliente &c) const;
    virtual Cliente* clone() const =0;
    float getCredito() const;
    string getNome() const;
    string getCognome() const;
    int getId() const;

protected:
    enum EccezioneCliente
    {
       CreditoInsufficiente
    };
    void addCredito(float s);
    void subCredito(float s);
};

#endif // CLIENTE_H

#ifndef CLIENTE_H
#define CLIENTE_H
#include<string>
using std::string;

class Cliente
{
private:
    int codice;
    float credito;
    string nome;
    string cognome;
public:
    Cliente(int cod=0, float cre=0, string nom="NULL", string cog="NULL");
    virtual ~Cliente()=0;
    virtual string toString() const;
    virtual float Pagamento(float s);
    virtual void Ricarica(float s);

    float getCredito() const;
    string getNome() const;
    string getCognome() const;
protected:
    enum EccezioneCliente
    {
       CreditoInsufficiente
    };
    void addCredito(float s);
    void subCredito(float s);
};

#endif // CLIENTE_H

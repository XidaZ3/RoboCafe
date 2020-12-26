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
    virtual bool operator==(const Cliente &c) const;
    virtual bool operator!=(const Cliente &c) const;
    virtual Cliente* clone() const =0;
    float getCredito() const;
    string getNome() const;
    string getCognome() const;
    int getCodice() const;

protected:
    enum EccezioneCliente
    {
       CreditoInsufficiente
    };
    void addCredito(float s);
    void subCredito(float s);
};

#endif // CLIENTE_H

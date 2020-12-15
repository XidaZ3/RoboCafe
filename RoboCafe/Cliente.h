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
    virtual ~Cliente();
    virtual string toString() const;
    virtual float Pagamento(const float &s) const =0;
    float getCredito() const;
    string getNome() const;
    string getCognome() const;
};

#endif // CLIENTE_H

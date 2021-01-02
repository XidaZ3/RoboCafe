#include "Model/Model.h"

Vettore<DeepPtr<Prodotto>> Model::getOrdini() const
{
    return prodotti_ordinati;
}

Risorse Model::getRisorse()
{
    return risorse;
}

Vettore<DeepPtr<Prodotto> > Model::getProdotti() const
{
    return menu;
}

void Model::setRisorse(const Risorse &value)
{
    risorse = value;
}

float Model::getPortafoglio() const
{
    return portafoglio;
}

unsigned int Model::getOrdineSize() const
{
    return prodotti_ordinati.getSize();
}

Prodotto *Model::getProdottoAt(int index)
{
    return menu[index].ptr;
}

Risorse Model::getRisorse() const
{
    return risorse;
}

Vettore<DeepPtr<Prodotto>> Model::getErrori() const
{
    return errori;
}

Cliente *Model::getUtenteAttivo() const
{
    return utenteAttivo;
}

void Model::setUtenteAttivo(Cliente *value)
{
    utenteAttivo = value;
}

const Vettore<DeepPtr<Cliente>>& Model::getClientiDb() const
{
    return clientiDb;
}

void Model::incrementaContaClienti()
{
    contaClienti++;
}

int Model::getContaClienti() const
{
    return contaClienti;
}

Model::Model(){
    utenteAttivo=nullptr;
    readFromFile();
    risorse.readFromFile();
};
Model::~Model(){
    writeToFile();
    risorse.writeToFile();
};

void Model::preparaOrdine(Risorse& risorse)
{
    errori.clear();
    for(auto it=prodotti_ordinati.begin();it!=prodotti_ordinati.end();)
    {
        try{
            (**it).preparazione(risorse);
            it++;
        }catch(int e)
        {
            errori.push_back(*it);
            prodotti_ordinati.erase(it);
        }
    }

}

void Model::ritiroConto(float s)
{
    float sommapagata=utenteAttivo->Pagamento(s);
    portafoglio+=sommapagata;
}

void Model::ricaricaCredito(float s)
{
    utenteAttivo->Ricarica(s);
}

float Model::calcolaTotale()
{
    float totale =0;
    for(auto i = prodotti_ordinati.begin(); i!=prodotti_ordinati.end();i++)
    {
        totale+= (*i)->calcoloPrezzo();
    }
    return totale;
}

void Model::stampaScontrino(Vettore<DeepPtr<Prodotto>> prodotti)
{
    scontrino = "";
    for(auto it=prodotti.begin();it!=prodotti.end();it++){
        scontrino+=(**it).toString();
    }
    //codice per avvisare il controller di aggiornare la gui
}

Cliente* Model::cercaCliente(int i)
{
    Cliente *c =nullptr;
    bool stop=false;

    for(auto it = clientiDb.begin();!stop&&it!= clientiDb.end(); it++)
        if((**it).getId()== i)
        {
            c = &(**it);
            stop = true;
        }
    if(c)
        return c;
    else
        throw EccezioniCliente::ClienteInesistente;
}

void Model::prelevaPortafoglio(float s)
{
    if(portafoglio < s)
        throw EccezioniModel::CreditoNonPrelevabile;
    else
        if(s<0)
            throw EccezioniModel::CreditoNegativo;
        else
            portafoglio-=s;
}

void Model::cancellaProdotto(int index){
    prodotti_ordinati.erase(index);
}

void Model::cancellaOrdine(){
    prodotti_ordinati.clear();
}

void Model::cancellaMenu()
{
    menu.clear();
}

void Model::cancellaCliente(int id)
{
    bool stop = false;
    for(Vettore<DeepPtr<Cliente>>::iterator i=clientiDb.begin();!stop&&i!=clientiDb.end();i++)
    {
        if((*i)->getId()==id)
        {
            clientiDb.erase(i);
            stop = true;
        }
    }

    if(clientiDb.getSize()!=0)
        utenteAttivo=&**clientiDb.begin();
    else
        utenteAttivo=nullptr;
}

void Model::aggiungiOrdine(Prodotto* prodotto)
{
    auto i = DeepPtr<Prodotto>(prodotto);
    prodotti_ordinati.push_back(i);
}

void Model::aggiungiProdotto(Prodotto *prodotto)
{
    auto i = DeepPtr<Prodotto>(prodotto);
    menu.push_back(i);
}

void Model::aggiungiCliente(Cliente *cliente)
{
    auto i = DeepPtr<Cliente>(cliente);
    clientiDb.push_back(i);
}

void Model::upgradePlus()
{
    //Solo sottotipi di ClienteStandard possono diventare Plus
    if(dynamic_cast<ClienteStandard*>(utenteAttivo))
    {
        utenteAttivo->Pagamento(20);
        ClientePlus *aux=new ClientePlus(*utenteAttivo);
        cancellaCliente(utenteAttivo->getId());
        aggiungiCliente(aux);
        utenteAttivo= aux;
    }
    else
        throw EccezioniCliente::ClienteNonStandard;
}

void Model::upgradeLivello()
{
    if(dynamic_cast<ClientePlus*>(utenteAttivo))
    {
        static_cast<ClientePlus*>(utenteAttivo)->upgradeLivello();
    }
    else
        throw EccezioniCliente::ClienteNonPlus;
}

Prodotto* Model::cercaProdotto(unsigned int idProdotto){
    Prodotto* ret =nullptr;
    bool stop=false;
    for(auto it = menu.begin(); !stop && it!= menu.end(); it++)
        if((**it).getIdProdotto() == idProdotto)
        {
            ret = &(**it);
            stop = true;
        }
    if(ret)
        return ret;
    else throw EccezioniPreparazione::ProdottoInesistente;
}

void Model::readFromFile()
{
    QString path("../RoboCafe/Controller/Files/model.json");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Impossibile aprire il file");
        return;
    }

    QByteArray byteArr = file.readAll();
    QJsonDocument doc (QJsonDocument::fromJson(byteArr));
    QJsonObject model = doc.object();
    if(model.contains("lastIdCliente") && model["lastIdCliente"].isDouble())
        contaClienti=model["lastIdCliente"].toInt();
    if(model.contains("portafoglio") && model["portafoglio"].isDouble())
        portafoglio=model["portafoglio"].toInt();
    file.close();
}

void Model::writeToFile() const
{
    QJsonObject model;
    model.insert("lastIdCliente",contaClienti);
    model.insert("portafoglio",portafoglio);
    QJsonDocument doc(model);
    QByteArray bytes = doc.toJson();
    QString path("../RoboCafe/Controller/Files/model.json");
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

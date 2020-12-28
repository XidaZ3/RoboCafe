#include "Model/Model.h"
#include "Model/Eccezioni.h"
#include "Model/ClientePlus.h"
#include "Model/ClienteStandard.h"
#include "Model/Dipendente.h"
#include "Te.h"
#include "Caffe.h"
#include "Pizza.h"

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

string Model::getErrori() const
{
    return errori;
}

bool Model::getTerminePreparazione() const
{
    return terminePreparazione;
}

Cliente *Model::getUtenteAttivo() const
{
    return utenteAttivo;
}

void Model::setUtenteAttivo(Cliente *value)
{
    utenteAttivo = value;
}

Vettore<DeepPtr<Cliente> > Model::getClientiDb() const
{
    return clientiDb;
}

Model::Model(){
    portafoglio = 100;
    utenteAttivo = new ClienteStandard();
    menu = Vettore<DeepPtr<Prodotto>>();
    prodotti_ordinati = Vettore<DeepPtr<Prodotto>>();


    clientiDb.push_back(new ClienteStandard(1,"Mario","Rossi",1000));
    clientiDb.push_back(new ClientePlus(2,"Gianni","Morandi",1000,1000,2));
    clientiDb.push_back(new Dipendente(3,"Pino","Bho",1000));
    Vettore<DeepPtr<Cliente>>::iterator i = clientiDb.begin();
    utenteAttivo = &**++i;
    std::cout<<utenteAttivo->toJsonString()<<std::endl;

    menu.resize(10);
    DeepPtr<Prodotto>ptr1 = DeepPtr<Prodotto>(new Caffe(2,"Caffe Ristretto",1.0,0.1,23,Dimensione::Medio));
    menu.push_back(ptr1);
    DeepPtr<Prodotto>ptr2 = DeepPtr<Prodotto>(new Pizza(3,"Pizza Margherita",5.5,180,689));
    menu.push_back(ptr2);
    for(int i = 0;i<10;i++)
    {
        DeepPtr<Prodotto>ptr = DeepPtr<Prodotto>(new Te(1,"Te al limone",1.5,0.8,231,Dimensione::Medio,0,0.1,2,true));
        menu.push_back(ptr);
    }

    //    risorse.rifornituraAcqua();
    //    risorse.rifornituraCaffe();
    //    risorse.rifornituraLatte();
    //    risorse.rifornituraPizza();
    //    risorse.rifornituraTe();

    terminePreparazione = false;


};
Model::~Model(){};

float Model::preparaOrdine(Risorse& risorse)
{
    errori="";
    float totale=0;
    for(auto it=prodotti_ordinati.begin();it!=prodotti_ordinati.end();)
    {
        try{
            (**it).Preparazione(risorse);
            totale+=(**it).CalcoloPrezzo();
            it++;
        }catch(int e)
        {
            prodotti_ordinati.erase(it);

            errori += "Risorse insufficienti per preparare: \n"+(**it).toString();
            std::cout<<errori<<std::endl;

        }
    }

    return totale;
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
    Cliente *c;
    bool stop=false;

    for(auto it = clientiDb.begin();!stop&&it!= clientiDb.end(); it++)
        if((**it).getCodice()== i)
        {
            c = &(**it);
            stop = true;
        }
    if(c)
        return c;
    else
        throw Eccezioni::ClienteInesistente;
}

void Model::prelevaPortafoglio(float s)
{
    if(portafoglio < s)
        throw CreditoNonPrelevabile;
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

void Model::aggiungiOrdine(Prodotto* prodotto)
{
  try{
        auto i = DeepPtr<Prodotto>(prodotto);
        prodotti_ordinati.push_back(i);
  }
  catch(int e)
  {
        //Errore prodotto richiesto non presente nel menu.
    }
}

void Model::upgradePlus()
{
    //Da fare meglio
    //Solo sottotipi di ClienteStandard possono diventare Plus
    if(dynamic_cast<ClienteStandard*>(utenteAttivo))
    {
        utenteAttivo->Pagamento(20);
        ClientePlus *aux=new ClientePlus(*utenteAttivo);
        delete utenteAttivo;
        utenteAttivo= aux;
    }
    else
        throw Eccezioni::ClienteNonStandard;
}

void Model::upgradeLivello()
{
    if(dynamic_cast<ClientePlus*>(utenteAttivo))
    {
        static_cast<ClientePlus*>(utenteAttivo)->upgradeLivello();
    }
    else
        throw Eccezioni::ClienteNonPlus;
}

Prodotto* Model::cercaProdotto(unsigned int idProdotto){
    Prodotto* ret;
  bool stop=false;
    for(auto it = menu.begin(); !stop && it!= menu.end(); it++)
        if((**it).getId_prodotto() == idProdotto) {ret = &(**it); stop = true;}
  if(ret) return ret;
  else throw Eccezioni::ProdottoInesistente;
}

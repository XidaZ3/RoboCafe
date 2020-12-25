#include "Model/Model.h"
#include "Model/Eccezioni.h"
#include "Model/ClientePlus.h"
#include "Model/ClienteStandard.h"

Risorse Model::getRisorse() const
{
    return risorse;
}

void Model::setRisorse(const Risorse &value)
{
    risorse = value;
}

float Model::getPortafoglio() const
{
    return portafoglio;
}

Model::Model(){
    portafoglio = 100;
};
Model::~Model(){};

float Model::preparaOrdine(Risorse& risorse)
 {
        errori="";
        float totale=0;

        for(Vettore<DeepPtr<Prodotto>>::iterator it=prodotti_ordinati.begin();it!=prodotti_ordinati.end();it++)
    {
      try{
        (**it).Preparazione(risorse);
        totale+=(**it).CalcoloPrezzo();
      }catch(EccezioniPreparazione e)
      {
        prodotti_ordinati.erase(it);
        errori += "Risorse insufficienti per preparare: "+(**it).toString();
      }
    }

    return totale;
 }

 void Model::ritiroConto(float s)
 {
        float sommapagata=(*utente).Pagamento(s);
        portafoglio+=sommapagata;
 }

 void Model::stampaScontrino(Vettore<DeepPtr<Prodotto>> prodotti)
 {
        scontrino = "";
        for(Vettore<DeepPtr<Prodotto>>::iterator it=prodotti.begin();it!=prodotti.end();it++){
        scontrino+=(**it).toString();
    }
    //codice per avvisare il controller di aggiornare la gui
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

void Model::aggiungiOrdine(int id_Prodotto)
{
  try{
    prodotti_ordinati.push_back(cercaProdotto(id_Prodotto));
  }
  catch(Eccezioni e)
  {
        //Errore prodotto richiesto non presente nel menu.
  }
}

void Model::upgradePlus()
{
//Da fare meglio
    //Solo sottotipi di ClienteStandard possono diventare Plus
    if(dynamic_cast<ClienteStandard*>(utente))
    {
        utente->Pagamento(20);
        ClientePlus *aux=new ClientePlus(*utente);
        delete utente;
        utente= aux;
    }
}

Prodotto* Model::cercaProdotto(unsigned int idProdotto){
    Prodotto* ret;
  bool stop=false;
    for(Vettore<DeepPtr<Prodotto>>::iterator it = menu.begin(); stop || it!= menu.end(); it++)
    if((**it).getId_prodotto() == idProdotto) {ret = &(**it); stop = true;}
  if(ret) return ret;
  else throw Eccezioni::ProdottoInesistente;
}

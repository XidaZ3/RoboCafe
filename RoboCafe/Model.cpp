#include "Model.h"

float Model::preparaOrdine(Risorse& risorse)
 {
        errori="";
        float totale=0;

        for(Vettore<DeepPtr<Prodotto>>::iterator it=prodotti_ordinati.begin();it!=prodotti_ordinati.end();it++)
    {
      try{
        it->Preparazione(risorse);
        totale+=it->CalcolaPrezzo();
      }catch(ImpastoPizzaInsufficiente e)
      {
        prodotti_ordinati.erase(it);
        errori += "Non sono riuscito a fare: "+it->getNome();
      }
      catch(AcquaInsufficiente e)
      {
      }
      catch(CaffeInsufficiente e)
      {
      }
      catch(FiltriTeInsufficienti e)
      {
      }
      catch(LitriLatteInsufficiente e)
      {
      }
    }

    return totale;
 }

 void Model::ritiroConto(float s)
 {
        float sommapagata=utente.Pagamento(s);
        portafoglio+=sommapagata;
 }

 void Model::stampaScontrino(vettore<DeepPtr<Prodotto>> prodotti)
 {
        scontrino = "";
        for(vettore<DeepPtr<Prodotto>>::iterator it=prodotti.begin();it!=prodotti.end();it++){
        scontrino+=it->toString();
    }
    //codice per avvisare il controller di aggiornare la gui
 }

 void Model::prelevaPortafoglio(float s)
 {
        if(portafoglio.getPortafoglio-s>0)
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

void Model::aggiungiOrdine(int id)
{
    try{
        prodotti_ordinati.push(cercaProdotto(id));
  }
  catch(ProdottoInesistente e)
  {
  }
}

void Model::upgradePlus()
{
//Da fare meglio
    if(dynamic_cast<ClienteStandard>(utente))
        utente=ClientePlus(utente);
}

Prodotto Model::cercaProdotto(int idProdotto){
    Prodotto ret;
  bool stop=false;
    for(vettore<DeepPtr<Prodotto>>::iterator it = menu.begin(); stop || it!= menu.end(); it++)
    if(it->getCodiceProdotto() == idProdotto) {ret = *it; stop = true;}
  if(ret) return ret;
  else throw ProdottoInesistente;
}

#include "Controller.h"
#include <iostream>
using namespace std;

void Controller::setView(View *value)
{
    view = value;
    inizializzaClienteWidget();
    inizializzaMenu();
    inizializzaGestoreWidget();
}

void Controller::setModel(Model *value)
{
    model = value;
}

void Controller::preparaOrdine()
{
    if(model->getOrdineSize()>0)
    {
        Risorse r=model->getRisorse();
        view->mostraTotale(model->preparaOrdine(r));
        model->setRisorse(r);
    }

}

void Controller::inizializzaMenu()
{
    view->inizializzaListaProdotti(getProdotti());
}

void Controller::confermaOrdine()
{
    preparaOrdine();
    view->inizializzaListaScontrino(getOrdini());
    annullaOrdine();
    view->inizializzaListaOrdine(getOrdini());

    view->abilitaNuovoOrdine(true);
    view->abilitaAnnullamento(false);
    view->abilitaConferma(false);
}

void Controller::annullaOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::rimuoviOrdine(int index)
{
    model->cancellaProdotto(index);
    if(model->getOrdini().getSize()==0){
        view->abilitaConferma(false);
        view->abilitaAnnullamento(false);
    }
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::aggiungiOrdine(int index)
{
    model->aggiungiOrdine(index);
    if(model->getOrdini().getSize()==1){
        view->abilitaConferma(true);
        view->abilitaNuovoOrdine(false);
        view->abilitaAnnullamento(true);
    }
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::nuovoOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(getOrdini());
    view->inizializzaListaScontrino(getOrdini());
    view->mostraTotale(0);
    view->abilitaNuovoOrdine(false);
}

std::vector<Prodotto*> Controller::getProdotti()
{
    auto vet = model->getProdotti();
    std::vector<Prodotto*> ret = std::vector<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
}

std::vector<Prodotto*> Controller::getOrdini()
{
    auto vet = model->getOrdini();
    std::vector<Prodotto*> ret = std::vector<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
}

Controller::Controller(QObject *parent):QObject(parent)
{

}

void Controller::inizializzaClienteWidget() const{
    view->inizializzaCliente("xd","lul",1,2,50);
}

void Controller::inizializzaGestoreWidget() const
{
    Risorse r=model->getRisorse();
    cout<<model->getPortafoglio()<<r.getLitriAcqua()<<r.getCialdeCaffe()<<r.getLitriLatte()<<r.getFiltriTe()<<r.getImpastiPizze()<<endl;
    view->inizializzaGestore(model->getPortafoglio(),r.getLitriAcqua(),r.getCialdeCaffe(),r.getLitriLatte(),r.getFiltriTe(),r.getImpastiPizze());
}

void Controller::refillAcqua() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraAcqua();
    model->setRisorse(aux);
    view->clickAcqua(model->getRisorse().getLitriAcqua());
}

void Controller::refillCaffe() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraCaffe();
    model->setRisorse(aux);
    view->clickCaffe(model->getRisorse().getCialdeCaffe());
}

void Controller::refillLatte() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraLatte();
    model->setRisorse(aux);
    view->clickLatte(model->getRisorse().getLitriLatte());
}

void Controller::refillTe() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraTe();
    model->setRisorse(aux);
    view->clickTe(model->getRisorse().getFiltriTe());
}

void Controller::refillPizze() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraPizza();
    model->setRisorse(aux);
    view->clickPizze(model->getRisorse().getImpastiPizze());
}

void Controller::Preleva() const
{

    model->prelevaPortafoglio(view->getLneCreditoText().toFloat());
    view->clickPreleva(model->getPortafoglio());
}


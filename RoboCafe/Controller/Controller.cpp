#include "Controller.h"

void Controller::setView(View *value)
{
    view = value;
}

void Controller::setModel(Model *value)
{
    model = value;
}

void Controller::preparaOrdine()
{
    if(model->getOrdineSize()>0)
    {
        view->mostraTotale(model->preparaOrdine(model->getRisorse()));
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

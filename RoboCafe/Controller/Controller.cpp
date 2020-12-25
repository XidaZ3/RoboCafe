#include "Controller.h"
#include <iostream>
using namespace std;

void Controller::setView(View *value)
{
    view = value;
    inizializzaClienteWidget();
}

void Controller::setModel(Model *value)
{
    model = value;
}

Controller::Controller(QObject *parent):QObject(parent)
{

}

void Controller::inizializzaClienteWidget() const{
    view->inizializzaCliente("xd","lul",1,2,3);
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


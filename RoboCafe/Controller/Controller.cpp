#include "Controller.h"

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

void Controller::inizializzaClienteWidget(){
    view->inizializzaCliente("xd","lul",1,2,3);
}

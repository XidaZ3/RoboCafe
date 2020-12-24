#include "Controller.h"

void Controller::setView(View *value)
{
    view = value;
}

void Controller::setModel(Model *value)
{
    model = value;
}

Controller::Controller(QObject *parent):QObject(parent)
{

}

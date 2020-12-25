#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Model/Model.h"
#include "View/View.h"

class Controller: public QObject
{
    Q_OBJECT
private:
    View *view;
    Model *model;
public:
    explicit Controller(QObject *parent = nullptr);
    void setView(View *value);
    void setModel(Model *value);

    void inizializzaClienteWidget() const;
public slots:
    void refillAcqua() const;
    void refillCaffe() const;
    void refillLatte() const;
    void refillTe() const;
    void refillPizze() const;
};

#endif // CONTROLLER_H

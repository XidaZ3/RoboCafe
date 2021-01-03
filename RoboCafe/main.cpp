#include <iostream>
#include <math.h>
#include "View/ZonaGestoreWidget.h"
#include <QApplication>
#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScrollArea *q = new QScrollArea();
    q->setWidgetResizable(true);

    Model m;
    View v;
    Controller c;
    q->setWidget(&v);
    v.setController(&c);
    c.setModel(&m);
    c.setView(&v);
    q->setMinimumWidth(1000);
    q->setMinimumHeight(1000);
    q->show();

    return a.exec();
}

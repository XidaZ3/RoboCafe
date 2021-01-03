#include <iostream>
#include <math.h>
//#include "Model/Vettore.h"
//#include "Model/Dipendente.h"
//#include "Model/ClientePlus.h"
//#include "Model/ClienteStandard.h"
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

    Model m;
    View v ;
    Controller c;
    v.setController(&c);
    c.setModel(&m);
    c.setView(&v);
    v.setMinimumWidth(500);
    v.setMinimumHeight(760);

    v.show();
    return a.exec();
}

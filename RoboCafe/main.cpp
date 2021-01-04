#include <iostream>
#include <math.h>
#include <QApplication>
#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScrollArea s;
    Model m;
    View v ;
    Controller c;
    v.setController(&c);
    c.setModel(&m);
    c.setView(&v);
    s.setWidget(&v);
    s.setWidgetResizable(true);
    s.setMinimumSize(1200,540);
    s.show();
    return a.exec();
}

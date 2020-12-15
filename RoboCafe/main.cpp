#include <iostream>
#include <math.h>
#include "Vettore.h"
#include "Dipendente.h"
#include "mainwindow.h"
#include <QApplication>
#include "Model.h"

const float Dipendente::sconto = 0.8f;

int main(int argc, char *argv[])
{
    Vettore<int> v1;
    Vettore<int> v2(5,6);
    v1.append(v2).append(Vettore<int>(2,3));
    std::cout<<v1<<std::endl<<v2<<std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

#include <iostream>
#include <math.h>
#include "vettore.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    vettore<int> v1;
    vettore<int> v2(5,6);
    v1.append(v2).append(vettore<int>(2,3));
    std::cout<<v1<<std::endl<<v2<<std::endl;

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

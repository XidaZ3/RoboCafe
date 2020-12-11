#include "mainwindow.h"
#include <iostream>
#include <math.h>
using namespace std;

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    cout<<"Hello world";
    w.show();
    return a.exec();
}

#include <iostream>
#include <math.h>
#include "Vettore.h"
#include "Dipendente.h"
#include "ClientePlus.h"
#include "ClienteStandard.h"
#include "mainwindow.h"
#include <QApplication>
#include "Model.h"

using std::cout;
using std::endl;

const float Dipendente::sconto = 0.8f;

int main(int argc, char *argv[])
{
    Vettore<int> v1;
    Vettore<int> v2(5,6);
    v1.append(v2).append(Vettore<int>(2,3));
    std::cout<<v1<<std::endl<<v2<<std::endl;

    int conto=100;
    ClientePlus palazzinaro;
    ClienteStandard povero;
    Dipendente dip;

    palazzinaro.Ricarica(100);
    povero.Ricarica(100);
    dip.Ricarica(100);

    palazzinaro.Pagamento(conto);
    povero.Pagamento(conto);
    dip.Pagamento(conto);

    cout<<"palazzinaro:"<<palazzinaro.getCredito()
       <<" povero:"<<povero.getCredito()
      <<" dip:"<<dip.getCredito()<<endl;

    cout<<"punti"<<palazzinaro.getPunti()<<endl;

    ClientePlus x(palazzinaro);
    if(x==palazzinaro)
        cout<<"funzia"<<endl;
    palazzinaro.Ricarica(2);
    if(x!=palazzinaro)
        cout<<"funzia"<<endl;

   // lmao->leggiCliente()

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

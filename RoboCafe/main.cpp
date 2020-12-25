#include <iostream>
#include <math.h>
//#include "Model/Vettore.h"
//#include "Model/Dipendente.h"
//#include "Model/ClientePlus.h"
//#include "Model/ClienteStandard.h"
#include <QApplication>

#include "Model/Model.h"
#include "View/View.h"
#include "Controller/Controller.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
//    Vettore<int> v1;
//    Vettore<int> v2(5);
//    v1.append(v2).append(Vettore<int>(2));
//    std::cout<<v1<<std::endl<<v2<<std::endl;

//    int conto=100;
//    ClientePlus palazzinaro;
//    ClienteStandard povero;
//    Dipendente dip;

//    palazzinaro.Ricarica(100);
//    povero.Ricarica(100);
//    dip.Ricarica(100);

//    palazzinaro.Pagamento(conto);
//    povero.Pagamento(conto);
//    dip.Pagamento(conto);

//    cout<<"palazzinaro:"<<palazzinaro.getCredito()
//       <<" povero:"<<povero.getCredito()
//      <<" dip:"<<dip.getCredito()<<endl;

//    cout<<"punti"<<palazzinaro.getPunti()<<endl;

//    ClientePlus x(palazzinaro);
//    if(x==palazzinaro)
//        cout<<"funzia"<<endl;
//    palazzinaro.Ricarica(2);
//    if(x!=palazzinaro)
//        cout<<"funzia"<<endl;

    // lmao->leggiCliente()

    //codice finale

    QApplication a(argc, argv);

    Model m;
    View v;
    Controller c;

    c.setModel(&m);
    c.setView(&v);
    v.setController(&c);
    v.show();
    return a.exec();
}

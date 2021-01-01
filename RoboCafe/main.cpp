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

//    Vettore<int> vet;
//    vet.resize(5);
//    vet.push_back(1);
//    vet.push_back(2);
//    vet.push_back(3);
//    vet.push_back(4);
//    vet.push_back(5);
//    std::cout<<vet.find(4)<<std::endl;
//    //codice finale
//    Vettore<int>::iterator it = vet.end();
//    vet.insert(7,--it);
//    std::cout<<vet<<std::endl;


    QApplication a(argc, argv);

    Model m;
    View v ;
    Controller c;

    v.setController(&c);
    c.setModel(&m);
    c.setView(&v);
    v.setGeometry(0,0,1920,1080);
    v.setMinimumWidth(1300);
    v.show();
    v.mostraErrori("Errore generico");

    return a.exec();
}

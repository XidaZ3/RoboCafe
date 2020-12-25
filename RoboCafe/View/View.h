#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <vector>
#include "ProdottoItemWidget.h"
#include "OrdineItemWidget.h"
#include "ScontrinoItemWidget.h"
#include "ProdottoListWidget.h"
#include "OrdineListWidget.h"
#include "ScontrinoListWidget.h"
#include "MostraProdottoWidget.h"
#include "ZonaClienteWidget.h"
#include "ZonaGestoreWidget.h"
#include<string>
using std::string;
#include <iomanip>
#include <sstream>

//da eliminare
#include "Model/Vettore.h"
#include "Model/Te.h"
#include "Model/DeepPtr.h"

class Controller;

class View : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    ProdottoListWidget* listaProdotti;
    OrdineListWidget* listaOrdini;
    ScontrinoListWidget* listaScontrino;
    QScrollArea* scrollAreaProdotti;
    QScrollArea* scrollAreaOrdine;
    QScrollArea* scrollAreaScontrino;

    QLabel* lblMenu;
    QLabel* lblOrdine;
    QLabel* lblScontrino;

    MostraProdottoWidget *mostraProdottoWidget;
    ZonaClienteWidget *zonaClienteWidget;
    ZonaGestoreWidget *zonaGestoreWidget;
    QPushButton* confermaOrdine;
    QPushButton* annullaOrdine;

public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    void setController(Controller *value);

    void inizializzaListaProdotti();
    void inizializzaListaOrdine();
    void inizializzaListaScontrino();
    void inizializzaInterfacciaOrdini();
    void inizializzaCliente(string nome, string cognome, float credito,int livello=0,int punti=0);

    void refillAcqua(float acqua);
    void refillCaffe(int caffe);
    void refillLatte(float latte);
    void refillTe(int te);
    void refillPizze(int pizze);


};

#endif // VIEW_H

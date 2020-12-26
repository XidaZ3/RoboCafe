#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStringList>
#include <QDialog>
#include <vector>
#include "ProdottoItemWidget.h"
#include "OrdineItemWidget.h"
#include "ScontrinoItemWidget.h"
#include "CustomListWidget.h"
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
    CustomListWidget<ProdottoItemWidget*>* listaProdotti;
    CustomListWidget<OrdineItemWidget*>* listaOrdini;
    CustomListWidget<ScontrinoItemWidget*>* listaScontrino;
    QScrollArea* scrollAreaProdotti;
    QScrollArea* scrollAreaOrdine;
    QScrollArea* scrollAreaScontrino;

    QLabel* lblMenu;
    QLabel* lblOrdine;
    QLabel* lblScontrino;
    QLabel* lblTotale;
    QLabel* lblErrori;

    QDialog* dlgErrori;

    MostraProdottoWidget *mostraProdottoWidget;
    ZonaClienteWidget *zonaClienteWidget;
    ZonaGestoreWidget *zonaGestoreWidget;
    QPushButton* btnConfermaOrdine;
    QPushButton* btnAnnullaOrdine;
    QPushButton* btnNuovoOrdine;
    

    void inizializzaInterfacciaOrdini();
public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    void setController(Controller *value);
    void inizializzaListaProdotti(Vettore<Prodotto*> prodotti);
    void inizializzaListaOrdine(Vettore<Prodotto*> prodotti);
    void inizializzaListaScontrino(Vettore<Prodotto*> prodotti);
    void abilitaConferma(bool value);
    void abilitaAnnullamento(bool value);
    void abilitaNuovoOrdine(bool value);
    void abilitaMenu(bool value);
    void mostraTotale(float value);
    void mostraErrori(QString errori);

    void inizializzaCliente(string nome, string cognome, float credito,int livello=0,int punti=0);

    void clickAcqua(float acqua);
    void clickCaffe(int caffe);
    void clickLatte(float latte);
    void clickTe(int te);
    void clickPizze(int pizze);
    void clickPreleva(float credito);

    QString getLneCreditoText();
};

#endif // VIEW_H

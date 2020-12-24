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

class View : public QWidget
{
    Q_OBJECT
    private:
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

    void inizializzaListaProdotti();
    void inizializzaListaOrdine();
    void inizializzaListaScontrino();
    void inizializzaInterfacciaOrdini();
    
public:
    explicit View(QWidget *parent = nullptr);
    ~View();

};

#endif // VIEW_H

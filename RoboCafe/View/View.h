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
#include "CustomListWidget.h"

//da eliminare
#include "Model/Vettore.h"
#include "Model/Te.h"
#include "Model/DeepPtr.h"

class Controller;

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
    void setController(Controller *value);

public slots:
    void aggiungiProdottoInOrdine(Prodotto* prodotto);
    void mostraProdotto(Prodotto* prodotto);
    void rimuoviProdottoInOrdine(Prodotto* prodotto);
    void mostraOrdine();
    void svuotaOrdine();
    void mostraScontrino();

};

#endif // VIEW_H

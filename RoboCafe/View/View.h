#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include "ProdottoItemWidget.h"
#include "DettaglioProdottoItemWidget.h"
#include "ScontrinoItemWidget.h"
#include "MostraProdottoWidget.h"
#include "ZonaClienteWidget.h"
#include "ZonaGestoreWidget.h"

class View : public QWidget
{
    Q_OBJECT
    private:
    Vettore<ProdottoItemWidget*> listaProdotti;
    Vettore<DettaglioProdottoItemWidget*> listaOrdini;
    Vettore<ScontrinoItemWidget*> listaScontrino;
    QScrollArea* scrollAreaProdotti;
    QScrollArea* scrollAreaOrdine;
    QScrollArea* scrollAreaScontrino;
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
public slots:
    void aggiungiProdottoInOrdine(Prodotto* prodotto);
    void mostraProdotto(Prodotto* prodotto);
    void rimuoviProdottoInOrdine(Prodotto* prodotto);
    void mostraOrdine();
    void svuotaOrdine();
    void mostraScontrino();

};

#endif // VIEW_H

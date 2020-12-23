#include "CustomListWidget.h"
#include <QVBoxLayout>

CustomListWidget::CustomListWidget(const Vettore<ProdottoItemWidget*>& prodotti,QWidget *parent) : QWidget(parent), vettoreProdotti(prodotti)
{
     vLayout = new QVBoxLayout(this);

     for(auto i = vettoreProdotti.begin(); i!= vettoreProdotti.end(); i++){
         ProdottoItemWidget* item = new ProdottoItemWidget((*i)->getProdotto());
         vLayout->addWidget(item);
     }
}

CustomListWidget::CustomListWidget(const Vettore<ScontrinoItemWidget *> &scontrino, QWidget *parent) : QWidget(parent), vettoreScontrino(scontrino)
{
    vLayout = new QVBoxLayout(this);

    for(auto i = scontrino.begin(); i!= scontrino.end(); i++){
        DettaglioProdottoItemWidget* item = new DettaglioProdottoItemWidget((*i)->getProdotto());
        vLayout->addWidget(item);
    }
}

CustomListWidget::CustomListWidget(const Vettore<DettaglioProdottoItemWidget*>& prodotti, QWidget *parent): QWidget(parent),vettoreDettaglioProdotti(prodotti)
{
    vLayout = new QVBoxLayout(this);

    for(auto i = prodotti.begin(); i!= prodotti.end(); i++){
        DettaglioProdottoItemWidget* item = new DettaglioProdottoItemWidget((*i)->getProdotto());
        vLayout->addWidget(item);
    }
}

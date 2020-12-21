#include "ProdottoListWidget.h"
#include "ProdottoItemWidget.h"
#include <QVBoxLayout>

ProdottoListWidget::ProdottoListWidget(const Vettore<ProdottoItemWidget>& prodotti,QWidget *parent) : QWidget(parent), vettoreProdotti(prodotti)
{
     vLayout = new QVBoxLayout(this);

     for(auto i = prodotti.begin(); i!= prodotti.end(); i++){
         ProdottoItemWidget* item = new ProdottoItemWidget(i->getProdotto());
         vLayout->addWidget(item);
     }
}

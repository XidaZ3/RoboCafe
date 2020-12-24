#include "ProdottoListWidget.h"

void ProdottoListWidget::aggiungiWidget()
{
    pulisciLayout();
    for(auto i : vettoreProdotti)
    {
        mainLayout->addWidget(new ProdottoItemWidget(i));
    }
}

void ProdottoListWidget::pulisciLayout()
{
    QLayoutItem* item;
    while ( ( item = mainLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}

ProdottoListWidget::ProdottoListWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    vettoreProdotti = std::vector<ProdottoItemWidget*>();
}

ProdottoListWidget::~ProdottoListWidget()
{
    if(mainLayout)
        delete mainLayout;
}

ProdottoListWidget::ProdottoListWidget(const ProdottoListWidget &other):QWidget(other.parentWidget()),vettoreProdotti(other.vettoreProdotti){
    pulisciLayout();
    aggiungiWidget();
}

ProdottoListWidget &ProdottoListWidget::operator=(const ProdottoListWidget &other)
{
    if(this != & other){
        vettoreProdotti = std::vector<ProdottoItemWidget*>(other.vettoreProdotti);
        pulisciLayout();
        aggiungiWidget();
    }
    return *this;
}

void ProdottoListWidget::addItem(ProdottoItemWidget &value)
{
    vettoreProdotti.push_back(&value);
    pulisciLayout();
    aggiungiWidget();
}

ProdottoItemWidget& ProdottoListWidget::getItem(int index)
{
    return *vettoreProdotti[index];
}

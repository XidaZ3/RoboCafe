#include "OrdineListWidget.h"

void OrdineListWidget::aggiungiWidget()
{
    pulisciLayout();
    for(auto i : vettoreOrdini)
    {
        mainLayout->addWidget(new OrdineItemWidget(i));
    }
}

void OrdineListWidget::pulisciLayout()
{
    QLayoutItem* item;
    while ( ( item = mainLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}

OrdineListWidget::OrdineListWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    vettoreOrdini = std::vector<OrdineItemWidget*>();
}

OrdineListWidget::~OrdineListWidget()
{
    if(mainLayout)
        delete mainLayout;
}

OrdineListWidget::OrdineListWidget(const OrdineListWidget &other):QWidget(other.parentWidget()),vettoreOrdini(other.vettoreOrdini){
    pulisciLayout();
    aggiungiWidget();
}

OrdineListWidget &OrdineListWidget::operator=(const OrdineListWidget &other)
{
    if(this != & other){
        vettoreOrdini = std::vector<OrdineItemWidget*>(other.vettoreOrdini);
        pulisciLayout();
        aggiungiWidget();
    }
    return *this;
}

void OrdineListWidget::addItem(OrdineItemWidget &value)
{
    vettoreOrdini.push_back(&value);
    pulisciLayout();
    aggiungiWidget();
}

OrdineItemWidget& OrdineListWidget::getItem(int index)
{
    return *vettoreOrdini[index];
}

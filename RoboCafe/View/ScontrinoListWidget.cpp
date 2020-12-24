#include "ScontrinoListWidget.h"

void ScontrinoListWidget::aggiungiWidget()
{
    pulisciLayout();
    for(auto i : vettoreScontrino)
    {
        mainLayout->addWidget(new ScontrinoItemWidget(i));
    }
}

void ScontrinoListWidget::pulisciLayout()
{
    QLayoutItem* item;
    while ( ( item = mainLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}

ScontrinoListWidget::ScontrinoListWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    vettoreScontrino = std::vector<ScontrinoItemWidget*>();
}

ScontrinoListWidget::~ScontrinoListWidget()
{
    if(mainLayout)
        delete mainLayout;
}

ScontrinoListWidget::ScontrinoListWidget(const ScontrinoListWidget &other):QWidget(other.parentWidget()),vettoreScontrino(other.vettoreScontrino){
    pulisciLayout();
    aggiungiWidget();
}

ScontrinoListWidget &ScontrinoListWidget::operator=(const ScontrinoListWidget &other)
{
    if(this != & other){
        vettoreScontrino = std::vector<ScontrinoItemWidget*>(other.vettoreScontrino);
        pulisciLayout();
        aggiungiWidget();
    }
    return *this;
}

void ScontrinoListWidget::addItem(ScontrinoItemWidget &value)
{
    vettoreScontrino.push_back(&value);
    pulisciLayout();
    aggiungiWidget();
}

ScontrinoItemWidget& ScontrinoListWidget::getItem(int index)
{
    return *vettoreScontrino[index];
}

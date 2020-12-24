#include "ScontrinoItemWidget.h"

void ScontrinoItemWidget::pulisciBottomLayout()
{
    QLayoutItem* item;
    while ( ( item = bottomLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}

ScontrinoItemWidget::ScontrinoItemWidget(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    bottomLayout = new QVBoxLayout();
    vtrDettagli = std::vector<QLabel*>();

    lblNomeProdotto = new QLabel();
    lblPrezzo = new QLabel();
    topLayout->addWidget(lblNomeProdotto);
    topLayout->addWidget(lblPrezzo,Qt::AlignRight);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

ScontrinoItemWidget::~ScontrinoItemWidget()
{
    if(mainLayout)
        delete mainLayout;
    if(topLayout)
        delete topLayout;
    if(bottomLayout)
        delete bottomLayout;
    if(lblPrezzo)
        delete lblPrezzo;
    if(lblNomeProdotto)
        delete lblNomeProdotto;

}


ScontrinoItemWidget::ScontrinoItemWidget(const ScontrinoItemWidget &other):QWidget(other.parentWidget()), mainLayout(other.mainLayout),topLayout(other.topLayout),
bottomLayout(other.bottomLayout),lblPrezzo(other.lblPrezzo),lblNomeProdotto(other.lblNomeProdotto){}

ScontrinoItemWidget ScontrinoItemWidget::operator=(const ScontrinoItemWidget &other)
{
    if(this != &other)
    {
        if(lblPrezzo)
            delete lblPrezzo;
        if(lblNomeProdotto)
            delete lblNomeProdotto;

        lblPrezzo = new QLabel(other.lblPrezzo);
        lblNomeProdotto = new QLabel(other.lblNomeProdotto);

        vtrDettagli.clear();
        vtrDettagli.resize(other.vtrDettagli.size());
        for(auto i : other.vtrDettagli){
            QLabel* item = new QLabel(i);
            vtrDettagli.push_back(item);
            bottomLayout->addWidget(item);
        }

    }
    return *this;
}

void ScontrinoItemWidget::setNomeProdotto(QString nome)
{
    lblNomeProdotto->setText(nome);
}

void ScontrinoItemWidget::setPrezzoProdotto(QString prezzo)
{
    lblPrezzo->setText(prezzo);
}

void ScontrinoItemWidget::setDettagli(std::vector<QString> dettagli)
{
    vtrDettagli.clear();
    vtrDettagli.resize(dettagli.size());
    pulisciBottomLayout();
    for(auto i : dettagli){
        QLabel* item = new QLabel(i);
        vtrDettagli.push_back(item);
        bottomLayout->addWidget(item);
    }
}


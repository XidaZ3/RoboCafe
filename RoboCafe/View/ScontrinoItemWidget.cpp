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
    vtrDettagli = Vettore<QLabel*>();

    index = -1;

    lblNomeProdotto = new QLabel();
    QFont f("Arial", 9, QFont::DemiBold);
    lblNomeProdotto->setFont(f);
    lblPrezzo = new QLabel();
    lblPrezzo->setFont(f);
    topLayout->addWidget(lblNomeProdotto);
    topLayout->addWidget(lblPrezzo,Qt::AlignRight);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    setLayout(mainLayout);
}

ScontrinoItemWidget::~ScontrinoItemWidget()
{
    if(lblPrezzo)
        delete lblPrezzo;
    if(lblNomeProdotto)
        delete lblNomeProdotto;
    if(topLayout)
        delete topLayout;
    if(bottomLayout)
        delete bottomLayout;
    if(mainLayout)
        delete mainLayout;

}

ScontrinoItemWidget::ScontrinoItemWidget(const ScontrinoItemWidget &other):QWidget(other.parentWidget()), mainLayout(other.mainLayout),topLayout(other.topLayout),
bottomLayout(other.bottomLayout),lblPrezzo(other.lblPrezzo),lblNomeProdotto(other.lblNomeProdotto), index(other.index){}

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
        index = other.index;
        vtrDettagli.clear();
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

void ScontrinoItemWidget::setDettagliProdotto(Vettore<std::string> dettagli)
{
    pulisciBottomLayout();
    vtrDettagli.clear();
    for(auto i : dettagli){
        QLabel* item = new QLabel(QString::fromStdString(i));
        vtrDettagli.push_back(item);
        bottomLayout->addWidget(item);
    }
}

void ScontrinoItemWidget::setIndex(int value)
{
    index = value;
}


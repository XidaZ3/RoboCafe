#include "OrdineItemWidget.h"

void OrdineItemWidget::pulisciBottomLayout()
{
    QLayoutItem* item;
    while ( ( item = bottomLayout->takeAt( 0 ) ) != NULL )
    {
        delete item->widget();
        delete item;
    }
}

OrdineItemWidget::OrdineItemWidget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    bottomLayout = new QVBoxLayout();

    btnSubtract= new QPushButton();
    btnSubtract->setMaximumHeight(40);
    btnSubtract->setMaximumWidth(40);


    lblNomeProdotto = new QLabel();

    topLayout->addWidget(btnSubtract);
    topLayout->addWidget(lblNomeProdotto);

    vtrDettagli = std::vector<QLabel*>();
}

OrdineItemWidget::~OrdineItemWidget()
{
    if(mainLayout)
        delete mainLayout;
    if(topLayout)
        delete topLayout;
    if(bottomLayout)
        delete bottomLayout;
    if(btnSubtract)
        delete btnSubtract;
    if(lblNomeProdotto)
        delete lblNomeProdotto;
}

OrdineItemWidget::OrdineItemWidget(const OrdineItemWidget &other): QWidget(other.parentWidget()),mainLayout(other.mainLayout),
topLayout(other.topLayout),bottomLayout(other.bottomLayout),btnSubtract(other.btnSubtract),lblNomeProdotto(other.lblNomeProdotto),vtrDettagli(other.vtrDettagli){}

OrdineItemWidget &OrdineItemWidget::operator=(const OrdineItemWidget &other)
{
    if(this != &other)
    {
        if(btnSubtract)
            delete btnSubtract;
        if(lblNomeProdotto)
            delete lblNomeProdotto;

        btnSubtract = new QPushButton(other.btnSubtract);
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

void OrdineItemWidget::setNomeProdotto(QString nome)
{
    lblNomeProdotto->setText(nome);
}

void OrdineItemWidget::setNomeBottone(QString nome)
{
    btnSubtract->setText(nome);
}

void OrdineItemWidget::setDettagliProdotto(std::vector<QString> dettagli)
{
    vtrDettagli.clear();
    vtrDettagli.resize(dettagli.size());
    for(auto i: dettagli)
    {
        QLabel* item = new QLabel(i);
        vtrDettagli.push_back(item);
        bottomLayout->addWidget(item);
    }
}

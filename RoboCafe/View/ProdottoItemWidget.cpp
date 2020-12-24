#include "ProdottoItemWidget.h"

ProdottoItemWidget::ProdottoItemWidget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    btnSubtract = new QPushButton();
    btnSubtract->setMaximumHeight(40);
    btnSubtract->setMaximumWidth(40);

    lblNomeProdotto = new QLabel();

    mainLayout->addWidget(btnSubtract);
    mainLayout->addWidget(lblNomeProdotto);
}


ProdottoItemWidget::~ProdottoItemWidget()
{
    if(mainLayout)
        delete mainLayout;
    if(btnSubtract)
        delete btnSubtract;
    if(lblNomeProdotto)
        delete lblNomeProdotto;
}

ProdottoItemWidget::ProdottoItemWidget(const ProdottoItemWidget &other): QWidget(other.parentWidget()), mainLayout(other.mainLayout), btnSubtract(other.btnSubtract),
lblNomeProdotto(other.lblNomeProdotto){}

ProdottoItemWidget &ProdottoItemWidget::operator=(const ProdottoItemWidget &other)
{
    if(this != &other)
    {
        if(btnSubtract)
            delete btnSubtract;
        if(lblNomeProdotto)
            delete lblNomeProdotto;

        btnSubtract = new QPushButton(other.btnSubtract);
        lblNomeProdotto = new QLabel(other.lblNomeProdotto);

    }
    return *this;
}

void ProdottoItemWidget::setNomeProdotto(QString nome)
{
    lblNomeProdotto->setText(nome);
}

void ProdottoItemWidget::setNomeBottone(QString nome)
{
    btnSubtract->setText(nome);
}

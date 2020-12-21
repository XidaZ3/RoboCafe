#include "ProdottoItemWidget.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>

Prodotto *ProdottoItemWidget::getProdotto() const
{
    return prodotto;
}

void ProdottoItemWidget::setProdotto(Prodotto *value)
{
    prodotto = value;
}

ProdottoItemWidget::ProdottoItemWidget(Prodotto* p, QWidget *parent): QWidget(parent), prodotto(p)
{
    QHBoxLayout* mylayout = new QHBoxLayout(this);
    QPushButton* btnSubtract = new QPushButton("-", this);
    btnSubtract->setMaximumHeight(40);
    btnSubtract->setMaximumWidth(40);
    QLabel* lblProdotto = new QLabel(QString::fromStdString(prodotto->getNome_prodotto()), this);

    mylayout->addWidget(btnSubtract);
    mylayout->addWidget(lblProdotto);
}

ProdottoItemWidget::ProdottoItemWidget():prodotto(nullptr){}

ProdottoItemWidget::ProdottoItemWidget(const ProdottoItemWidget &other): QWidget(other.parentWidget()) ,prodotto(other.prodotto){}

ProdottoItemWidget &ProdottoItemWidget::operator=(const ProdottoItemWidget &other)
{
    if(this != &other)
    {
        if(prodotto != nullptr)
            delete prodotto;
        prodotto = other.prodotto;
    }
    return *this;
}

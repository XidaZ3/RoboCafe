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
    QPushButton* btnSubtract = new QPushButton("+");
    btnSubtract->setMaximumHeight(40);
    btnSubtract->setMaximumWidth(40);
    QString nome = QString::fromStdString(prodotto->getNome_prodotto());
    QLabel* lblProdotto = new QLabel(nome);

    mylayout->addWidget(btnSubtract);
    mylayout->addWidget(lblProdotto);
}

ProdottoItemWidget::ProdottoItemWidget():prodotto(nullptr){}

ProdottoItemWidget::~ProdottoItemWidget()
{
    if(prodotto)
        delete prodotto;
}

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

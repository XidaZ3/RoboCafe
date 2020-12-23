#include "DettaglioProdottoItemWidget.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "Model/Vettore.h"

DettaglioProdottoItemWidget::DettaglioProdottoItemWidget(Prodotto *p, QWidget *parent): QWidget(parent), prodotto(p)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* topLayout = new QHBoxLayout();
    QVBoxLayout* bottomLayout = new QVBoxLayout;
    QPushButton* btnSubtract = new QPushButton("-");
    btnSubtract->setMaximumHeight(40);
    btnSubtract->setMaximumWidth(40);
    topLayout->addWidget(btnSubtract);

    QLabel* lblProdotto = new QLabel(QString::fromStdString(prodotto->getNome_prodotto()));
    topLayout->addWidget(lblProdotto);
    topLayout->setSpacing(10);


    Vettore<std::string> vettoreDettagli = getDettagli(prodotto);
    for(auto i = vettoreDettagli.begin(); i!= vettoreDettagli.end();i++)
    {
        QLabel* item = new QLabel(QString::fromStdString(*i));
        item->setFont(QFont("Arial",8));
        bottomLayout->addWidget(item);
    }
    bottomLayout->setAlignment(Qt::AlignRight);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    mainLayout->setSpacing(0);
    setLayout(mainLayout);
}

DettaglioProdottoItemWidget::~DettaglioProdottoItemWidget()
{
    delete prodotto;
}

DettaglioProdottoItemWidget::DettaglioProdottoItemWidget(): prodotto(nullptr){}

DettaglioProdottoItemWidget::DettaglioProdottoItemWidget(const DettaglioProdottoItemWidget &other): QWidget(other.parentWidget()) ,prodotto(other.prodotto){}

DettaglioProdottoItemWidget &DettaglioProdottoItemWidget::operator=(const DettaglioProdottoItemWidget &other)
{
    if(this != &other)
    {
        if(prodotto != nullptr)
            delete prodotto;
        prodotto = other.prodotto;
    }
    return *this;
}

Prodotto *DettaglioProdottoItemWidget::getProdotto() const
{
    return prodotto;
}

void DettaglioProdottoItemWidget::setProdotto(Prodotto *value)
{
    prodotto = value;
}

Vettore<std::string> DettaglioProdottoItemWidget::getDettagli(Prodotto *prodotto) const
{
    QStringList dettagli = QString::fromStdString(prodotto->getDettagli()).split(',',Qt::SkipEmptyParts);
    Vettore<std::string> result;
    result.resize(dettagli.size());
    for(auto i: dettagli){
        result.push_back(i.toStdString());
    }
    return result;
}

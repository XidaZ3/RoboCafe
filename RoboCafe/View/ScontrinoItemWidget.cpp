#include "ScontrinoItemWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include "Model/Vettore.h"

ScontrinoItemWidget::ScontrinoItemWidget(Prodotto* p,QWidget *parent) : QWidget(parent), prodotto(p)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    QVBoxLayout* lblLayout = new QVBoxLayout();

    QString nome = QString::fromStdString(prodotto->getNome_prodotto());
    QLabel* lblProdotto = new QLabel(nome);
    lblLayout->addWidget(lblProdotto);

    Vettore<std::string> vettoreDettagli = getDettagli(prodotto);
    for(auto i = vettoreDettagli.begin(); i!= vettoreDettagli.end();i++)
    {
        QLabel* item = new QLabel(QString::fromStdString(*i));
        item->setFont(QFont("Arial",8));
        lblLayout->addWidget(item);
    }
    mainLayout->addLayout(lblLayout);
    std::string prezzo = std::to_string(std::round(prodotto->CalcoloPrezzo()*100.0)/100.0)+" €";
    QLabel* lblPrezzo = new QLabel(QString::fromStdString(prezzo));
    mainLayout->addWidget(lblPrezzo,Qt::AlignRight);

    setLayout(mainLayout);
}

ScontrinoItemWidget::~ScontrinoItemWidget()
{
    if(prodotto)
        delete prodotto;
}

ScontrinoItemWidget::ScontrinoItemWidget():prodotto(nullptr){}

ScontrinoItemWidget::ScontrinoItemWidget(const ScontrinoItemWidget &other):QWidget(other.parentWidget()),prodotto(other.getProdotto()){}
ScontrinoItemWidget ScontrinoItemWidget::operator=(const ScontrinoItemWidget &other)
{
    if(this != &other)
    {
        if(prodotto != nullptr)
            delete prodotto;
        prodotto = other.prodotto;
    }
    return *this;
}

Prodotto *ScontrinoItemWidget::getProdotto() const
{
    return prodotto;
}

void ScontrinoItemWidget::setProdotto(Prodotto *value)
{
    prodotto = value;
}

Vettore<std::string> ScontrinoItemWidget::getDettagli(Prodotto *prodotto) const
{
    QStringList dettagli = QString::fromStdString(prodotto->getDettagli()).split(',',Qt::SkipEmptyParts);
    Vettore<std::string> result;
    result.resize(dettagli.size());
    for(auto i: dettagli){
        result.push_back(i.toStdString());
    }
    return result;
}


#include "ProdottoItemWidget.h"

int ProdottoItemWidget::getIndex() const
{
    return index;
}

void ProdottoItemWidget::setIndex(int value)
{
    index = value;
}

ProdottoItemWidget::ProdottoItemWidget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    btnAdd = new QPushButton();
    btnAdd->setMaximumHeight(40);
    btnAdd->setMaximumWidth(40);

    lblNomeProdotto = new QLabel();
    index =-1;

    mainLayout->addWidget(btnAdd);
    mainLayout->addWidget(lblNomeProdotto);

    connect(btnAdd,SIGNAL(clicked()),this,SLOT(buttonTriggered()));
}


ProdottoItemWidget::~ProdottoItemWidget()
{
    if(btnAdd)
        delete btnAdd;
    if(lblNomeProdotto)
        delete lblNomeProdotto;
    if(mainLayout)
        delete mainLayout;
}

ProdottoItemWidget::ProdottoItemWidget(const ProdottoItemWidget &other): QWidget(other.parentWidget()), mainLayout(other.mainLayout), btnAdd(other.btnAdd),
lblNomeProdotto(other.lblNomeProdotto), index(other.index){}

ProdottoItemWidget &ProdottoItemWidget::operator=(const ProdottoItemWidget &other)
{
    if(this != &other)
    {
        if(btnAdd)
            delete btnAdd;
        if(lblNomeProdotto)
            delete lblNomeProdotto;

        btnAdd = new QPushButton(other.btnAdd);
        lblNomeProdotto = new QLabel(other.lblNomeProdotto);
        index = other.index;

    }
    return *this;
}

void ProdottoItemWidget::setNomeProdotto(QString nome)
{
    lblNomeProdotto->setText(nome);
}

void ProdottoItemWidget::setNomeBottone(QString nome)
{
    btnAdd->setText(nome);
}

QPushButton &ProdottoItemWidget::getBottone() const
{
    return *btnAdd;
}

void ProdottoItemWidget::buttonTriggered()
{
    emit(btnClicked(index));
}

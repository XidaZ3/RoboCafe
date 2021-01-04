#include "ProdottoItemWidget.h"

ProdottoItemWidget::ProdottoItemWidget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    btnAdd = new QPushButton();
    btnAdd->setMaximumHeight(40);
    btnAdd->setMaximumWidth(40);

    lblNomeProdotto = new QLabel();
    QFont f("Arial", 9, QFont::DemiBold);
    lblNomeProdotto->setFont(f);
    index =-1;

    mainLayout->addWidget(btnAdd);
    mainLayout->addWidget(lblNomeProdotto);

    connect(btnAdd,SIGNAL(clicked()),this,SLOT(buttonTriggered()));
}

ProdottoItemWidget::~ProdottoItemWidget()
{
    delete btnAdd;
    delete lblNomeProdotto;
    delete mainLayout;
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

int ProdottoItemWidget::getIndex() const
{
    return index;
}

void ProdottoItemWidget::setIndex(int value)
{
    index = value;
}

void ProdottoItemWidget::buttonTriggered()
{
    emit(btnClicked(index));
}

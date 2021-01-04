#include "OrdineItemWidget.h"

void OrdineItemWidget::pulisciBottomLayout()
{
    QLayoutItem* item;
    while ( ( item = bottomLayout->takeAt( 0 ) ) != nullptr )
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

    index =-1;


    lblNomeProdotto = new QLabel();
    QFont f("Arial", 9, QFont::DemiBold);
    lblNomeProdotto->setFont(f);

    topLayout->addWidget(btnSubtract);
    topLayout->addWidget(lblNomeProdotto);
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);

    connect(btnSubtract,SIGNAL(clicked()),this,SLOT(buttonTriggered()));
}

OrdineItemWidget::~OrdineItemWidget()
{
    delete btnSubtract;
    delete lblNomeProdotto;
    delete topLayout;
    delete bottomLayout;
    delete mainLayout;
}

void OrdineItemWidget::setNomeProdotto(QString nome)
{
    lblNomeProdotto->setText(nome);
}

void OrdineItemWidget::setNomeBottone(QString nome)
{
    btnSubtract->setText(nome);
}

void OrdineItemWidget::setDettagliProdotto(Vettore<std::string> dettagli)
{
    pulisciBottomLayout();
    vtrDettagli.clear();
    for(auto i: dettagli)
    {
        QLabel* item = new QLabel(QString::fromStdString(i));
        vtrDettagli.push_back(item);
        bottomLayout->addWidget(item);
    }
}

QPushButton &OrdineItemWidget::getBottone() const
{
    return *btnSubtract;
}

int OrdineItemWidget::getIndex() const
{
    return index;
}

void OrdineItemWidget::setIndex(int value)
{
    index = value;
}

void OrdineItemWidget::buttonTriggered()
{
    emit(btnClicked(index));
}

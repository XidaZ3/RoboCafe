#include "View.h"
#include "ProdottoItemWidget.h"
#include "MostraProdottoWidget.h"
#include "ZonaClienteWidget.h"
#include "ZonaGestoreWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include "View/ProdottoListWidget.h"
#include "Model/Vettore.h"
#include "Model/Te.h"
#include <iostream>

View::View(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QHBoxLayout* topLayout = new QHBoxLayout();
    QHBoxLayout* bottomLayout = new QHBoxLayout();

    //Zona Cliente
    ZonaClienteWidget *zonaClienteWidget = new ZonaClienteWidget(this);
    zonaClienteWidget->setGeometry(0,0,400,200);

    //topLayout->addWidget(zonaClienteWidget);
    //topLayout->setAlignment(Qt::Alignment(Qt::AlignLeft));

    //Ordini
    Vettore<ProdottoItemWidget> listaProdotti;
    listaProdotti.resize(10);
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te al Limone",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te alla Pesca",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te alla Menta",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te Verde",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te Rosso",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te Nero",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te Bianco",3.5,0.2)));
    listaProdotti.push_back(ProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2)));

    ProdottoListWidget* lista = new ProdottoListWidget(listaProdotti,this);
    QScrollArea* scrollArea = new QScrollArea(this);

    scrollArea->setWidget(lista);
    scrollArea->setMaximumHeight(200);
    scrollArea->setMaximumWidth(300);

    bottomLayout->addWidget(scrollArea);

    //mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    MostraProdottoWidget *mostraProdotto = new MostraProdottoWidget(this);
    mostraProdotto->setGeometry(400,0,400,200);

    ZonaGestoreWidget *zonaGestore = new ZonaGestoreWidget(this);
    zonaGestore->setGeometry(800,0,400,200);



    setLayout(mainLayout);
}

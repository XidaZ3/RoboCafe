#include "View.h"
#include "ProdottoItemWidget.h"
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
    QHBoxLayout* topLayout = new QHBoxLayout(this);
    QHBoxLayout* bottomLayout = new QHBoxLayout(this);

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

    mainLayout->addItem(topLayout);
    mainLayout->addItem(bottomLayout);
}

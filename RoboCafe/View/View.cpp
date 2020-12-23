#include "View.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QListWidget>
#include <QLabel>
#include "CustomListWidget.h"
#include "Model/Vettore.h"
#include "Model/Te.h"

void View::initializeLists()
{
    listaProdotti =Vettore<ProdottoItemWidget*>();
    listaProdottiDettagliata =Vettore<DettaglioProdottoItemWidget*>();
    listaScontrino = Vettore<ScontrinoItemWidget*>();

    listaProdotti.resize(10);
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te al Limone",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te alla Pesca",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te alla Menta",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Verde",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Rosso",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Nero",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Bianco",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2)));

    listaProdottiDettagliata.resize(10);
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));

    listaScontrino.resize(10);
    listaScontrino.push_back(new ScontrinoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaScontrino.push_back(new ScontrinoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaScontrino.push_back(new ScontrinoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaScontrino.push_back(new ScontrinoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));
    listaScontrino.push_back(new ScontrinoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2,200,Dimensione::Grande,1,0.2,2,1)));

}

View::View(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* mainLayout = new QVBoxLayout();
    QHBoxLayout* topLayout = new QHBoxLayout();
    QHBoxLayout* bottomLayout = new QHBoxLayout();
    initializeLists();

    CustomListWidget* lista = new CustomListWidget(listaProdotti);
    CustomListWidget* listaDettagli = new CustomListWidget(listaProdottiDettagliata);
    CustomListWidget* scontrino = new CustomListWidget(listaScontrino);

    lista->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QScrollArea* scrollAreaProdotti = new QScrollArea(this);
    scrollAreaProdotti->setWidget(lista);

    QScrollArea* scrollAreaProdottiDettagliati = new QScrollArea(this);
    scrollAreaProdottiDettagliati->setWidget(listaDettagli);

    QScrollArea* scrollAreaScontrino = new QScrollArea(this);
    scrollAreaScontrino->setWidget(scontrino);

    bottomLayout->setSizeConstraint(QLayout::SetFixedSize);

    bottomLayout->addWidget(scrollAreaProdotti);
    bottomLayout->addWidget(scrollAreaProdottiDettagliati);
    bottomLayout->addWidget(scrollAreaScontrino);


    mainLayout->addItem(topLayout);
    mainLayout->addItem(bottomLayout);
    setLayout(mainLayout);
}

View::~View()
{
}

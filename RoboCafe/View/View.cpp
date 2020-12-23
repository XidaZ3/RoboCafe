#include "View.h"
#include "ProdottoItemWidget.h"
#include "MostraProdottoWidget.h"
#include "ZonaClienteWidget.h"
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
    initializeLists();

    //Zona Cliente
    ZonaClienteWidget *zonaClienteWidget = new ZonaClienteWidget(this);
    zonaClienteWidget->setGeometry(0,0,400,200);

    //topLayout->addWidget(zonaClienteWidget);
    //topLayout->setAlignment(Qt::Alignment(Qt::AlignLeft));

    CustomListWidget* lista = new CustomListWidget(listaProdotti);
    CustomListWidget* listaDettagli = new CustomListWidget(listaProdottiDettagliata);
    CustomListWidget* scontrino = new CustomListWidget(listaScontrino);

    QScrollArea* scrollAreaProdotti = new QScrollArea(this);
    QScrollArea* scrollAreaProdottiDettagliati = new QScrollArea(this);
    QScrollArea* scrollAreaScontrino = new QScrollArea(this);

    scrollAreaProdotti->setWidget(lista);
    scrollAreaProdottiDettagliati->setWidget(listaDettagli);
    scrollAreaScontrino->setWidget(scontrino);

    scrollAreaProdotti->setGeometry(0,250,200,400);
    scrollAreaProdottiDettagliati->setGeometry(250,250,200,400);
    scrollAreaScontrino->setGeometry(500,250,200,400);

    MostraProdottoWidget *mostraProdotto = new MostraProdottoWidget(this);
    mostraProdotto->setGeometry(400,0,400,200);

}

View::~View()
{
}

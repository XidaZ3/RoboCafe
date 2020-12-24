#include "View.h"
#include "Controller/Controller.h"

void View::setController(Controller *value)
{
    controller = value;

    //da aggiungere connect
}

void View::inizializzaListaProdotti()
{
    //Prendere il vettore<DeepPtr<Prodotto>> dal modello tramite il controller
    //Vettore<DeepPtr<Prodotto>> vettoreMenu = controller->getMenu();
    //listaProdotti =Vettore<ProdottoItemWidget*>();
    //listaProdotti.resize(vettoreMenu.size());

    //inizializzare la lista di ProdottoItemWidget
    /*for(auto i = vettoreMenu.begin();i!=vettoreMenu.end(); i++){
        listaProdotti.push_back(new ProdottoItemWidget(**i);
     }
    */

    //Da eliminare quando implementiamo il controller
    listaProdotti =Vettore<ProdottoItemWidget*>();
    listaProdotti.resize(10);
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te al Limone",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te alla Pesca",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te alla Menta",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Verde",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Rosso",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Nero",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Bianco",3.5,0.2)));
    listaProdotti.push_back(new ProdottoItemWidget(new Te(1,2,"Te Giallo",3.5,0.2)));

}

void View::inizializzaListaOrdine()
{
    //Prendere il vettore<DeepPtr<Prodotto>> dal modello tramite il controller
    //Vettore<DeepPtr<Prodotto>> vettoreOrdini = controller->getOrdini();
    listaOrdini =Vettore<DettaglioProdottoItemWidget*>();
    //listaProdottiDettagliata.resize(vettoreOrdini.size());

    //inizializzare la lista di ProdottoItemWidget
    /*for(auto i = vettoreOrdini.begin();i!=vettoreOrdini.end(); i++){
        listaProdottiDettagliata.push_back(new DettaglioProdottoItemWidget(**i);
     }
    */
}

void View::inizializzaListaScontrino()
{
    //Come si fa a determinare quali sono gli elementi da mostrare nello scontrino?
    //Come li si ottiene dal model?
    listaScontrino= Vettore<ScontrinoItemWidget*>();
}

void View::inizializzaInterfacciaOrdini()
{
    inizializzaListaProdotti();
    inizializzaListaOrdine();
    inizializzaListaScontrino();

    CustomListWidget* lista = new CustomListWidget(listaProdotti,this);
    CustomListWidget* listaDettagli = new CustomListWidget(listaOrdini,this);
    CustomListWidget* scontrino = new CustomListWidget(listaScontrino,this);

    QLabel* lblMenu = new QLabel("Menu", this);
    lblMenu->setStyleSheet("QLabel { font-size: 15px}");
    lblMenu->setGeometry(10,230,70,20);
    QLabel* lblOrdine = new QLabel("Lista Ordini", this);
    lblOrdine->setStyleSheet("QLabel { font-size: 15px}");
    lblOrdine->setGeometry(660,230,70,20);
    QLabel* lblScontrino = new QLabel("Scontrino", this);
    lblScontrino->setStyleSheet("QLabel { font-size: 15px}");
    lblScontrino->setGeometry(880,230,70,20);

    scrollAreaProdotti = new QScrollArea(this);
    scrollAreaOrdine = new QScrollArea(this);
    scrollAreaScontrino = new QScrollArea(this);

    scrollAreaProdotti->setWidget(lista);
    scrollAreaOrdine->setWidget(listaDettagli);
    scrollAreaScontrino->setWidget(scontrino);

    scrollAreaProdotti->setGeometry(10,250,200,400);
    scrollAreaOrdine->setGeometry(660,250,200,400);
    scrollAreaScontrino->setGeometry(880,250,200,400);
}

View::View(QWidget *parent) : QWidget(parent)
{
    //Zona Cliente
    zonaClienteWidget = new ZonaClienteWidget(this);
    zonaClienteWidget->setGeometry(0,0,400,200);

    //topLayout->addWidget(zonaClienteWidget);
    //topLayout->setAlignment(Qt::Alignment(Qt::AlignLeft));

    inizializzaInterfacciaOrdini();

    confermaOrdine = new QPushButton("Conferma Ordine",this);
    confermaOrdine->setGeometry(670,700,90,30);

    annullaOrdine = new QPushButton("Annulla Ordine",this);
    annullaOrdine->setGeometry(770,700,90,30);

    mostraProdottoWidget = new MostraProdottoWidget(this);
    mostraProdottoWidget->setGeometry(240,250,400,200);

    zonaGestoreWidget = new ZonaGestoreWidget(this);
    zonaGestoreWidget->setGeometry(400,0,400,200);

}

View::~View()
{
}

void View::aggiungiProdottoInOrdine(Prodotto* prodotto)
{
    //controller->aggiungiOrdine(prodotto);
    mostraOrdine();
}

void View::mostraProdotto(Prodotto *prodotto)
{
    delete mostraProdottoWidget;
    mostraProdottoWidget = new MostraProdottoWidget(this); //Necessaria modifica al costruttore di MostraProdottoWidget affinchè accetti un prodotto
}

void View::rimuoviProdottoInOrdine(Prodotto* prodotto)
{
    //controller->rimuoviOrdine(prodotto);
    mostraOrdine();
}

void View::mostraOrdine()
{
    inizializzaListaOrdine();
    delete scrollAreaOrdine->widget();
    scrollAreaOrdine->setWidget(new CustomListWidget(listaOrdini,this));
}

void View::svuotaOrdine()
{
    //controller->svuotaOrdine();
    mostraOrdine();
}

void View::mostraScontrino()
{

}

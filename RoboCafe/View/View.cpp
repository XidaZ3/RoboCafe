#include "View.h"
#include "Controller/Controller.h"

void View::setController(Controller *value)
{
    controller = value;
    connect(zonaGestoreWidget->getBtnAcqua(),SIGNAL(clicked()),controller,SLOT(refillAcqua()));
    connect(zonaGestoreWidget->getBtnCaffe(),SIGNAL(clicked()),controller,SLOT(refillCaffe()));
    connect(zonaGestoreWidget->getBtnLatte(),SIGNAL(clicked()),controller,SLOT(refillLatte()));
    connect(zonaGestoreWidget->getBtnTe(),SIGNAL(clicked()),controller,SLOT(refillTe()));
    connect(zonaGestoreWidget->getBtnPizze(),SIGNAL(clicked()),controller,SLOT(refillPizze()));
    //da aggiungere connect
}

void View::inizializzaListaProdotti()
{
}

void View::inizializzaListaOrdine()
{
}

void View::inizializzaListaScontrino()
{
}

void View::inizializzaInterfacciaOrdini()
{
    listaProdotti = new ProdottoListWidget();
    listaOrdini = new OrdineListWidget();
    listaScontrino = new ScontrinoListWidget();

    lblMenu = new QLabel("Menu", this);
    lblMenu->setStyleSheet("QLabel { font-size: 15px}");
    lblMenu->setGeometry(10,230,70,20);

    lblOrdine = new QLabel("Lista Ordini", this);
    lblOrdine->setStyleSheet("QLabel { font-size: 15px}");
    lblOrdine->setGeometry(660,230,70,20);

    lblScontrino = new QLabel("Scontrino", this);
    lblScontrino->setStyleSheet("QLabel { font-size: 15px}");
    lblScontrino->setGeometry(880,230,70,20);

    scrollAreaProdotti = new QScrollArea(this);
    scrollAreaOrdine = new QScrollArea(this);
    scrollAreaScontrino = new QScrollArea(this);

    scrollAreaProdotti->setWidget(listaProdotti);
    scrollAreaOrdine->setWidget(listaOrdini);
    scrollAreaScontrino->setWidget(listaScontrino);

    scrollAreaProdotti->setGeometry(10,250,200,400);
    scrollAreaOrdine->setGeometry(660,250,200,400);
    scrollAreaScontrino->setGeometry(880,250,200,400);
}

void View::inizializzaCliente(string nome, string cognome, float credito,int livello,int punti)
{
    zonaClienteWidget->setCmbNome(QString::fromStdString(nome));
    zonaClienteWidget->setLneCognome(QString::fromStdString(cognome));
    zonaClienteWidget->setLneCredito(QString::fromStdString(std::to_string(credito)));
    zonaClienteWidget->setLblLivelloEff(QString::fromStdString(std::to_string(livello)));
    zonaClienteWidget->setQProgressBar();
}

void View::refillAcqua(float acqua)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << acqua;
    zonaGestoreWidget->setlblAcqua(QString::fromStdString(stream.str()));
}

void View::refillCaffe(int caffe)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << caffe;
    zonaGestoreWidget->setlblCaffe(QString::fromStdString(stream.str()));
}

void View::refillLatte(float latte)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << latte;
    zonaGestoreWidget->setlblLatte(QString::fromStdString(stream.str()));
}

void View::refillTe(int te)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) <<te;
    zonaGestoreWidget->setlblTe(QString::fromStdString(stream.str()));
}

void View::refillPizze(int pizze)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << pizze;
    zonaGestoreWidget->setlblPizze(QString::fromStdString(stream.str()));
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
    delete listaProdotti;
    delete listaOrdini;
    delete listaScontrino;
    delete scrollAreaProdotti;
    delete scrollAreaOrdine;
    delete scrollAreaScontrino;
    delete lblMenu;
    delete lblOrdine;
    delete lblScontrino;
    delete mostraProdottoWidget;
    delete zonaClienteWidget;
    delete zonaGestoreWidget;
    delete confermaOrdine;
    delete annullaOrdine;
}


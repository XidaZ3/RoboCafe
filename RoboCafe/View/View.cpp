#include "View.h"
#include "Controller/Controller.h"

void View::setController(Controller *value)
{
    controller = value;

    //connect Zona Gestore
    connect(zonaGestoreWidget->getBtnPreleva(),SIGNAL(clicked()),controller,SLOT(Preleva()));
    connect(zonaGestoreWidget->getBtnAcqua(),SIGNAL(clicked()),controller,SLOT(refillAcqua()));
    connect(zonaGestoreWidget->getBtnCaffe(),SIGNAL(clicked()),controller,SLOT(refillCaffe()));
    connect(zonaGestoreWidget->getBtnLatte(),SIGNAL(clicked()),controller,SLOT(refillLatte()));
    connect(zonaGestoreWidget->getBtnTe(),SIGNAL(clicked()),controller,SLOT(refillTe()));
    connect(zonaGestoreWidget->getBtnPizze(),SIGNAL(clicked()),controller,SLOT(refillPizze()));
    //da aggiungere connect
    connect(btnConfermaOrdine, &QPushButton::clicked,controller,&Controller::confermaOrdine);
    connect(btnAnnullaOrdine, &QPushButton::clicked,controller,&Controller::annullaOrdine);
    connect(btnNuovoOrdine, &QPushButton::clicked,controller,&Controller::nuovoOrdine);
}

void View::inizializzaListaProdotti(std::vector<Prodotto*> prodotti)
{
    if(listaProdotti != NULL)
        delete listaProdotti;
    listaProdotti = new CustomListWidget<ProdottoItemWidget*>(this);
    int index=0;
    for(auto prodotto: prodotti){
        listaProdotti->addItem(new ProdottoItemWidget(this));
        auto i = listaProdotti->getItem(index);
        i->setNomeBottone(QString("+"));
        i->setNomeProdotto(QString::fromStdString(prodotto->getNome_prodotto()));
        i->setIndex(index);
        connect(&(*i),SIGNAL(btnClicked(int)),controller,SLOT(aggiungiOrdine(int)));
        i++;
        index++;
    }
    scrollAreaProdotti->setWidget(listaProdotti);
}

void View::inizializzaListaOrdine(std::vector<Prodotto*> prodotti)
{
    if(listaProdotti != NULL)
        delete listaOrdini;
    listaOrdini = new CustomListWidget<OrdineItemWidget*>(this);
    int index=0;
    for(auto prodotto:prodotti){
        listaOrdini->addItem(new OrdineItemWidget(this));
        auto i = listaOrdini->getItem(index);
        (*i).setNomeBottone(QString("-"));
        (*i).setNomeProdotto(QString::fromStdString(prodotto->getNome_prodotto()));
        QString stringaDettagliProdotto = QString::fromStdString(prodotto->getDettagli());
        QStringList listaDettagliProdotto = stringaDettagliProdotto.split(',',Qt::SkipEmptyParts);
        (*i).setDettagliProdotto(listaDettagliProdotto);
        (*i).setIndex(index);
        connect(&(*i),SIGNAL(btnClicked(int)),controller,SLOT(rimuoviOrdine(int)));
        i++;
        index++;
    }
    scrollAreaOrdine->setWidget(listaOrdini);
}

void View::inizializzaListaScontrino(std::vector<Prodotto*> prodotti)
{
    if(listaScontrino != NULL)
        delete listaScontrino;
    listaScontrino = new CustomListWidget<ScontrinoItemWidget*>(this);
    int index=0;
    for(auto prodotto:prodotti){
        listaScontrino->addItem(new ScontrinoItemWidget(this));
        auto i = listaScontrino->getItem(index);
        (*i).setPrezzoProdotto(QString::number(prodotto->CalcoloPrezzo(),'g',3)+QString(" €"));
        (*i).setNomeProdotto(QString::fromStdString(prodotto->getNome_prodotto()));
        QString stringaDettagliProdotto = QString::fromStdString(prodotto->getDettagli());
        QStringList listaDettagliProdotto = stringaDettagliProdotto.split(',',Qt::SkipEmptyParts);
        (*i).setDettagliProdotto(listaDettagliProdotto);
        (*i).setIndex(index);
        i++;
        index++;
    }
    scrollAreaScontrino->setWidget(listaScontrino);
}

void View::abilitaConferma(bool value)
{
    btnConfermaOrdine->setEnabled(value);
}

void View::abilitaAnnullamento(bool value)
{
    btnAnnullaOrdine->setEnabled(value);
}

void View::abilitaNuovoOrdine(bool value)
{
    btnNuovoOrdine->setEnabled(value);
}

void View::mostraTotale(float value)
{
    lblTotale->setText(QString::number(value,'g',4)+QString(" €"));
}

void View::mostraErrori(QString errori)
{
    lblErrori->setText(errori);
    //dlgErrori = new QDialog(lblErrori);
    //dlgErrori->show();
}

void View::inizializzaInterfacciaOrdini()
{
    listaProdotti = new CustomListWidget<ProdottoItemWidget*>(this);
    listaOrdini = new CustomListWidget<OrdineItemWidget*>(this);
    listaScontrino = new CustomListWidget<ScontrinoItemWidget*>(this);

    lblMenu = new QLabel("Menu", this);
    lblMenu->setStyleSheet("QLabel { font-size: 15px}");
    lblMenu->setGeometry(10,230,70,20);

    lblOrdine = new QLabel("Lista Ordini", this);
    lblOrdine->setStyleSheet("QLabel { font-size: 15px}");
    lblOrdine->setGeometry(660,230,70,20);

    lblScontrino = new QLabel("Scontrino", this);
    lblScontrino->setStyleSheet("QLabel { font-size: 15px}");
    lblScontrino->setGeometry(880,230,70,20);

    lblTotale = new QLabel("0.00 €",this);
    lblTotale->setStyleSheet("QLabel { font-size: 15px}");
    lblTotale->setGeometry(1040,700,70,20);

    scrollAreaProdotti = new QScrollArea(this);
    scrollAreaOrdine = new QScrollArea(this);
    scrollAreaScontrino = new QScrollArea(this);

    scrollAreaProdotti->setGeometry(10,250,200,400);
    scrollAreaOrdine->setGeometry(660,250,200,400);
    scrollAreaScontrino->setGeometry(880,250,200,400);
}

void View::inizializzaCliente(string nome, string cognome, float credito,int livello,int punti)
{
    zonaClienteWidget->setLneNome(QString::fromStdString(nome));
    zonaClienteWidget->setLneCognome(QString::fromStdString(cognome));
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << credito;
    zonaClienteWidget->setLneCredito(QString::fromStdString(stream.str()));
    zonaClienteWidget->setLblLivelloEff(QString::fromStdString(std::to_string(livello)));
    zonaClienteWidget->setLnePunti(QString::fromStdString(std::to_string(punti)));
    zonaClienteWidget->setPrgLivello(punti);
}

void View::inizializzaGestore(int portafoglio, float acqua, int caffe, float latte, int te, int pizze)
{
    std::stringstream stream;
    zonaGestoreWidget->setLblPortafoglioDati(QString::fromStdString(std::to_string(portafoglio)));

    stream << std::fixed << std::setprecision(2) << acqua;
    zonaGestoreWidget->setLblAcqua(QString::fromStdString(stream.str()));
    zonaGestoreWidget->setLblCaffe(QString::fromStdString(std::to_string(caffe)));

    stream.str("");
    stream << std::fixed << std::setprecision(2) << latte;
    zonaGestoreWidget->setLblLatte(QString::fromStdString(stream.str()));
    zonaGestoreWidget->setLblTe(QString::fromStdString(std::to_string(te)));
    zonaGestoreWidget->setLblPizze(QString::fromStdString(std::to_string(pizze)));
}

void View::clickAcqua(float acqua)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << acqua;
    zonaGestoreWidget->setLblAcqua(QString::fromStdString(stream.str()));
}

void View::clickCaffe(int caffe)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << caffe;
    zonaGestoreWidget->setLblCaffe(QString::fromStdString(stream.str()));
}

void View::clickLatte(float latte)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << latte;
    zonaGestoreWidget->setLblLatte(QString::fromStdString(stream.str()));
}

void View::clickTe(int te)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) <<te;
    zonaGestoreWidget->setLblTe(QString::fromStdString(stream.str()));
}

void View::clickPizze(int pizze)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << pizze;
    zonaGestoreWidget->setLblPizze(QString::fromStdString(stream.str()));
}

void View::clickPreleva(float credito)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << credito;
    zonaGestoreWidget->setLblPortafoglioDati(QString::fromStdString(stream.str()));
}

QString View::getLneCreditoText()
{
    return zonaGestoreWidget->getLneCredito();
}

View::View(QWidget *parent) : QWidget(parent)
{
    //Zona Cliente
    zonaClienteWidget = new ZonaClienteWidget(this);
    zonaClienteWidget->setGeometry(0,0,400,200);

    //topLayout->addWidget(zonaClienteWidget);
    //topLayout->setAlignment(Qt::Alignment(Qt::AlignLeft));

    inizializzaInterfacciaOrdini();

    btnConfermaOrdine = new QPushButton("Conferma Ordine",this);
    btnConfermaOrdine->setGeometry(670,700,90,30);
    btnConfermaOrdine->setEnabled(false);

    btnAnnullaOrdine = new QPushButton("Annulla Ordine",this);
    btnAnnullaOrdine->setGeometry(770,700,90,30);
    btnAnnullaOrdine->setEnabled(false);

    btnNuovoOrdine = new QPushButton("Nuovo Ordine",this);
    btnNuovoOrdine->setGeometry(870,700,90,30);
    btnNuovoOrdine->setEnabled(false);

    dlgErrori = new QDialog();
    lblErrori = new QLabel();

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
    delete btnConfermaOrdine;
    delete btnAnnullaOrdine;
}


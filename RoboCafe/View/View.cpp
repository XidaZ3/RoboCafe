#include "View.h"
#include "Controller/Controller.h"

void View::setController(Controller *value)
{
    controller = value;
    //connect Zona Cliente
    connect(zonaClienteWidget->getBtnCrea(),SIGNAL(clicked()),controller,SLOT(creaUtente()));
    connect(zonaClienteWidget->getBtnElimina(),SIGNAL(clicked()),controller,SLOT(eliminaUtente()));
    connect(zonaClienteWidget->getBtnLevelUp(),SIGNAL(clicked()),controller,SLOT(upgradeLivello()));
    connect(zonaClienteWidget->getBtnConverti(),SIGNAL(clicked()),controller,SLOT(convertiPunti()));
    connect(zonaClienteWidget->getBtnUpgrade(),SIGNAL(clicked()),controller,SLOT(upgradeUtente()));
    connect(zonaClienteWidget->getBtnDeposita(),SIGNAL(clicked()),controller,SLOT(depositaCredito()));
    connect(zonaClienteWidget->getCmbId(),SIGNAL(activated(int)),controller,SLOT(clienteSelezionato()));

    //connect Zona Gestore
    connect(zonaGestoreWidget->getBtnPreleva(),SIGNAL(clicked()),controller,SLOT(prelevaPortafoglio()));
    connect(zonaGestoreWidget->getBtnAcqua(),SIGNAL(clicked()),controller,SLOT(refillAcqua()));
    connect(zonaGestoreWidget->getBtnCaffe(),SIGNAL(clicked()),controller,SLOT(refillCaffe()));
    connect(zonaGestoreWidget->getBtnLatte(),SIGNAL(clicked()),controller,SLOT(refillLatte()));
    connect(zonaGestoreWidget->getBtnTe(),SIGNAL(clicked()),controller,SLOT(refillTe()));
    connect(zonaGestoreWidget->getBtnPizze(),SIGNAL(clicked()),controller,SLOT(refillPizze()));
    connect(mostraProdottoWidget,SIGNAL(conferma(Prodotto*)),controller,SLOT(aggiungiOrdine(Prodotto*)));

    //da aggiungere connect
    connect(btnConfermaOrdine, &QPushButton::clicked,controller,&Controller::confermaOrdine);
    connect(btnAnnullaOrdine, &QPushButton::clicked,controller,&Controller::annullaOrdine);
    connect(btnNuovoOrdine, &QPushButton::clicked,controller,&Controller::nuovoOrdine);
    connect(btnMostraGestore,SIGNAL(clicked()), controller,SLOT(mostraZonaGestore()));
}

void View::inizializzaListaProdotti(Vettore<Prodotto*> prodotti)
{
    if(listaProdotti != nullptr)
        delete listaProdotti;
    listaProdotti = new CustomListWidget<ProdottoItemWidget*>(this);
    int index=0;
    for(auto prodotto = prodotti.begin();prodotto != prodotti.end();prodotto++){
        listaProdotti->addItem(new ProdottoItemWidget(this));
        auto i = listaProdotti->getItem(index);
        i->setNomeBottone(QString("+"));
        i->setNomeProdotto(QString::fromStdString((*prodotto)->getNomeProdotto()));
        i->setIndex(index);
        connect(&(*i),SIGNAL(btnClicked(int)),controller,SLOT(mostraSceltaProdotto(int)));
        i++;
        index++;
    }
    scrollAreaProdotti->setWidget(listaProdotti);
}

void View::inizializzaListaOrdine(Vettore<Prodotto*> prodotti)
{
    if(listaProdotti != nullptr)
        delete listaOrdini;
    listaOrdini = new CustomListWidget<OrdineItemWidget*>(this);
    int index=0;
    for(auto prodotto = prodotti.begin();prodotto != prodotti.end();prodotto++){
        listaOrdini->addItem(new OrdineItemWidget(this));
        auto i = listaOrdini->getItem(index);
        (*i).setNomeBottone(QString("-"));
        (*i).setNomeProdotto(QString::fromStdString((*prodotto)->getNomeProdotto()));
        (*i).setDettagliProdotto((*prodotto)->getDettagli());
        (*i).setIndex(index);
        connect(&(*i),SIGNAL(btnClicked(int)),controller,SLOT(rimuoviOrdine(int)));
        i++;
        index++;
    }
    scrollAreaOrdine->setWidget(listaOrdini);
}

void View::inizializzaListaScontrino(Vettore<Prodotto*> prodotti)
{
    if(listaScontrino != nullptr)
        delete listaScontrino;
    listaScontrino = new CustomListWidget<ScontrinoItemWidget*>(this);
    int index=0;
    for(auto prodotto = prodotti.begin();prodotto != prodotti.end();prodotto++){
        listaScontrino->addItem(new ScontrinoItemWidget(this));
        auto i = listaScontrino->getItem(index);
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << (*prodotto)->calcoloPrezzo();
        (*i).setPrezzoProdotto(QString::fromStdString(stream.str()+" €"));
        (*i).setNomeProdotto(QString::fromStdString((*prodotto)->getNomeProdotto()));
        (*i).setDettagliProdotto((*prodotto)->getDettagli());
        (*i).setIndex(index);
        i++;
        index++;
    }

}

void View::inizializzaListaErrori(Vettore<Prodotto *> prodotti, int startIndex)
{
    if(listaScontrino != nullptr){
        int index=startIndex;
        for(auto prodotto = prodotti.begin();prodotto != prodotti.end();prodotto++){
            listaScontrino->addItem(new ScontrinoItemWidget(this));
            auto i = listaScontrino->getItem(index);
            (*i).setPrezzoProdotto("Risorse Insuff");
            (*i).setNomeProdotto(QString::fromStdString((*prodotto)->getNomeProdotto()));
            (*i).setDettagliProdotto((*prodotto)->getDettagli());
            (*i).setIndex(index);
            i++;
            index++;
        }
    }
    scrollAreaScontrino->setWidget(listaScontrino);
}

void View::inizializzaSceltaProdotto(Prodotto *prodotto)
{
    mostraProdottoWidget->setProdotto(prodotto);
}

void View::resetSceltaProdotto()
{
    mostraProdottoWidget->resetInterfaccia();
    mostraProdottoWidget->setGeometry(240,250,400,200);
    // zonaClienteWidget->getCmbId()->setDisabled(false);
}

void View::abilitaCmbId(bool value)
{
    zonaClienteWidget->setCmbEnabled(value);
}

void View::abilitaConfermaOrdine(bool value)
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

void View::abilitaMenu(bool value)
{
    scrollAreaProdotti->setEnabled(value);
}

void View::abilitaConfermaProdotto(bool value)
{
    mostraProdottoWidget->btnConfermaEnabled(value);
}

void View::mostraTotale(float value)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    lblTotale->setText(QString::fromStdString(stream.str()+" €"));
}

void View::mostraTotaleEffettivo(float value)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    lblTotaleEffettivo->setText(QString::fromStdString(stream.str()+" €"));
    lblTotaleEffettivo->show();
    lblTotaleEffettivoDesc->show();
}

void View::mostraSconto(float value)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << (value);
    QString string = QString::fromStdString(stream.str());
    lblSconto->setText("- "+string+" %");
    lblSconto->show();
}

void View::abilitaTotale(bool value)
{
    if(value){
        lblTotale->show();
        lblTotaleDesc->show();
        lblTotaleEffettivo->show();
        lblTotaleEffettivoDesc->show();
        lblSconto->show();
    }else{
        lblTotale->hide();
        lblTotaleDesc->hide();
        lblTotaleEffettivo->hide();
        lblTotaleEffettivoDesc->hide();
        lblSconto->hide();
    }

}

void View::aggiornaTransazione(float credito, float portafoglio, int punti)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << credito;
    zonaClienteWidget->setLblCreditoEff(QString::fromStdString(stream.str()));
    zonaClienteWidget->setLblCreditoEff(QString::fromStdString(stream.str()));
    zonaClienteWidget->setLblPuntiEff(QString::fromStdString(std::to_string(punti)));
    stream.str("");
    stream << std::fixed << std::setprecision(2) << portafoglio;
    zonaClienteWidget->setPrgLivello(punti);
    zonaGestoreWidget->setLblPortafoglioDati(QString::fromStdString(stream.str()));

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

    lblSconto = new QLabel(this);
    lblSconto->setStyleSheet("QLabel { font-size: 15px}");
    lblSconto->setGeometry(1080,725,70,20);
    lblSconto->hide();
    lblTotaleDesc = new QLabel("Totale parziale:",this);
    lblTotaleDesc->setStyleSheet("QLabel { font-size: 15px}");
    lblTotaleDesc->setGeometry(970,660,100,20);
    lblTotaleDesc->hide();
    lblTotaleEffettivoDesc = new QLabel("Totale effettivo:",this);
    lblTotaleEffettivoDesc->setStyleSheet("QLabel { font-size: 15px}");
    lblTotaleEffettivoDesc->setGeometry(1090,660,120,20);
    lblTotaleEffettivoDesc->hide();

    lblTotale = new QLabel("0.00 €",this);
    lblTotale->setStyleSheet("QLabel { font-size: 15px}");
    lblTotale->setGeometry(970,690,70,20);
    lblTotale->hide();

    lblTotaleEffettivo = new QLabel(this);
    lblTotaleEffettivo->setStyleSheet("QLabel { font-size: 15px}");
    lblTotaleEffettivo->setGeometry(1090,690,90,20);
    lblTotaleEffettivo->hide();

    scrollAreaProdotti = new QScrollArea(this);
    scrollAreaOrdine = new QScrollArea(this);
    scrollAreaScontrino = new QScrollArea(this);

    scrollAreaProdotti->setGeometry(10,250,200,400);
    scrollAreaOrdine->setGeometry(660,250,200,400);
    scrollAreaScontrino->setGeometry(880,250,200,400);
}

void View::inizializzaClientiCmb(Vettore<DeepPtr<Cliente>> vet)
{
    for(Vettore<DeepPtr<Cliente>>::iterator i=vet.begin();i!=vet.end();i++)
        zonaClienteWidget->addCmbId(QString::fromStdString(std::to_string((**i).getId())));
}

void View::aggiungiClienteCmb(Cliente *c)
{
    zonaClienteWidget->addCmbId(QString::fromStdString(std::to_string(c->getId())));
}

void View::togliClienteCmb(QString s)
{
    zonaClienteWidget->removeCurrentCmbId();
    zonaClienteWidget->setCmbText(s);
}

void View::leggiCliente(Cliente *cliente)
{
    if(cliente!=nullptr)
    {
        zonaClienteWidget->setLneNome(QString::fromStdString(cliente->getNome()));
        zonaClienteWidget->setLneCognome(QString::fromStdString(cliente->getCognome()));
        std::stringstream stream;
        stream << std::fixed << std::setprecision(2) << cliente->getCredito();
        zonaClienteWidget->setLblCreditoEff(QString::fromStdString(stream.str()));
        if(dynamic_cast<ClientePlus*>(cliente))
        {
            ClientePlus *aux = static_cast<ClientePlus*>(cliente);
            zonaClienteWidget->setLblLivelloEff(QString::fromStdString(std::to_string(aux->getLivello())));
            zonaClienteWidget->setLblPuntiEff(QString::fromStdString(std::to_string(aux->getPunti())));
            zonaClienteWidget->setPrgLivello(aux->getPunti());
        }
        else
        {
            zonaClienteWidget->setLblLivelloEff(QString::fromStdString("0"));
            zonaClienteWidget->setLblPuntiEff(QString::fromStdString("-PLUS-"));
            zonaClienteWidget->setPrgLivello(0);
        }
    }
    else
    {
        zonaClienteWidget->setLneNome("seleziona cliente!");
        zonaClienteWidget->setLneCognome("");
        zonaClienteWidget->setLblCreditoEff("");
        zonaClienteWidget->setLblLivelloEff("");
        zonaClienteWidget->setLblPuntiEff("");
        zonaClienteWidget->setPrgLivello(0);
    }
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

void View::initCreazione()
{
    setDisabled(true);
    creaUtenteWidget = new CreaUtenteWidget();
    connect(creaUtenteWidget->getBtnOk(),SIGNAL(clicked()),controller,SLOT(confermaUtente()));
    connect(creaUtenteWidget,SIGNAL(sigEnableView()),controller,SLOT(sloEnableView()));
}

void View::confermaCreazione(QString s)
{
    setDisabled(false);
    zonaClienteWidget->setCmbText(s);
    delete creaUtenteWidget;
}

void View::mostraErroreDialog(QString messaggio)
{
    erroreWidget=new ErroreWidget;
    erroreWidget->setLblMessaggio(messaggio);
    setDisabled(true);
    connect(erroreWidget->getOkConferma(),SIGNAL(clicked()),controller,SLOT(confermaErrore()));
    connect(erroreWidget,SIGNAL(sigEnableView()),controller,SLOT(sloEnableView()));
}

void View::confermaErrore()
{
    setDisabled(false);
    delete erroreWidget;
}

void View::clickAcqua(float acqua)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << acqua;
    zonaGestoreWidget->setLblAcqua(QString::fromStdString(stream.str()));
}

void View::clickCaffe(int caffe)
{
    zonaGestoreWidget->setLblCaffe(QString::fromStdString(std::to_string(caffe)));
}

void View::clickLatte(float latte)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << latte;
    zonaGestoreWidget->setLblLatte(QString::fromStdString(stream.str()));
}

void View::clickTe(int te)
{
    zonaGestoreWidget->setLblTe(QString::fromStdString(std::to_string(te)));
}

void View::clickPizze(int pizze)
{
    zonaGestoreWidget->setLblPizze(QString::fromStdString(std::to_string(pizze)));
}

void View::clickUpgradeLivello(int livello,int punti)
{
    zonaClienteWidget->setLblLivelloEff(QString::fromStdString(std::to_string(livello)));
    zonaClienteWidget->setLblPuntiEff(QString::fromStdString(std::to_string(punti)));
    zonaClienteWidget->setPrgLivello(punti);
}

void View::clickConvertiPunti(float credito)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << credito;
    zonaClienteWidget->setLblCreditoEff(QString::fromStdString(stream.str()));
    zonaClienteWidget->setLblPuntiEff("0");
    zonaClienteWidget->setPrgLivello(0);
}

void View::clickDepositaCredito(float credito,int punti)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << credito;
    zonaClienteWidget->setLblCreditoEff(QString::fromStdString(stream.str()));
    zonaClienteWidget->setLneDepositaText(QString::fromStdString(""));
    zonaClienteWidget->setLblPuntiEff(QString::fromStdString(std::to_string(punti)));
    zonaClienteWidget->setPrgLivello(punti);
}

void View::enableView(bool b)
{
    setEnabled(b);
}

void View::zonaGestoreShow() const
{
    zonaGestoreWidget->show();
}

void View::clickSelectCmb(Cliente *c)
{
    leggiCliente(c);
}

CreaUtenteWidget::tipoUtente View::getTipoSelezionato() const
{
    return creaUtenteWidget->getTipoSelezionato();
}

void View::clickPreleva(float credito)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << credito;
    zonaGestoreWidget->setLblPortafoglioDati(QString::fromStdString(stream.str()));
    zonaGestoreWidget->setLneCredito("");
}

QString View::getLneCreditoText() const
{
    return zonaGestoreWidget->getLneCredito();
}

QString View::getLneDepositaText() const
{
    return zonaClienteWidget->getLneDepositaText();
}

QString View::getCmbText() const
{
    return zonaClienteWidget->getCmbText();
}

QString View::getLneNomeCrea() const
{
    return creaUtenteWidget->getLneNome();
}

QString View::getLneCognomeCrea() const
{
    return creaUtenteWidget->getLneCognome();
}

View::View(QWidget *parent) : QWidget(parent)
{
    //Zona Cliente
    zonaClienteWidget = new ZonaClienteWidget(this);
    zonaClienteWidget->setGeometry(0,0,520,240);

    inizializzaInterfacciaOrdini();

    btnConfermaOrdine = new QPushButton("Conferma Ordine",this);
    btnConfermaOrdine->setGeometry(670,690,90,30);
    btnConfermaOrdine->setEnabled(false);

    btnAnnullaOrdine = new QPushButton("Annulla Ordine",this);
    btnAnnullaOrdine->setGeometry(770,690,90,30);
    btnAnnullaOrdine->setEnabled(false);

    btnNuovoOrdine = new QPushButton("Nuovo Ordine",this);
    btnNuovoOrdine->setGeometry(870,690,90,30);
    btnNuovoOrdine->setEnabled(false);

    mostraProdottoWidget = new MostraProdottoWidget(this);
    mostraProdottoWidget->setGeometry(240,250,400,200);
    abilitaConfermaProdotto(false);

    msgErrori = new QMessageBox(this);

    zonaGestoreWidget = new ZonaGestoreWidget();
    zonaGestoreWidget->setMaximumSize(200,100);

    btnMostraGestore = new QPushButton("Mostra zona gestore",this);
    btnMostraGestore->setGeometry(970,10,120,60);
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
    delete lblTotale;
    delete lblTotaleDesc;
    delete lblTotaleEffettivo;
    delete lblTotaleEffettivoDesc;
    delete mostraProdottoWidget;
    delete zonaClienteWidget;
    delete zonaGestoreWidget;
    delete btnConfermaOrdine;
    delete btnAnnullaOrdine;
}


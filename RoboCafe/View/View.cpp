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

void View::inizializzaListaProdotti(Vettore<DeepPtr<Prodotto>> prodotti)
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

void View::inizializzaListaOrdine(Vettore<DeepPtr<Prodotto>> prodotti)
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

void View::inizializzaListaScontrino(Vettore<DeepPtr<Prodotto>> prodotti)
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

void View::inizializzaListaErrori(Vettore<DeepPtr<Prodotto>> prodotti, int startIndex)
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

void View::inizializzaSceltaProdotto(Prodotto* prodotto)
{
    mostraProdottoWidget->setProdotto(prodotto);
    if(prodotto != nullptr)
        lblProdottoSelezionato->setText("Prodotto selezionato: "+QString::fromStdString(prodotto->getNomeProdotto()));
    else
        lblProdottoSelezionato->setText("Prodotto selezionato: ");
}

void View::resetSceltaProdotto()
{
    mostraProdottoWidget->resetInterfaccia();
    lblProdottoSelezionato->setText("Prodotto selezionato: ");
    mostraProdottoWidget->setProdotto(nullptr);
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

void View::abilitaSceltaProdotto(bool value)
{
    mostraProdottoWidget->setEnabled(value);
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

    lblMenu = new QLabel("Menu",this);
    lblMenu->setStyleSheet("QLabel { font-size: 15px}");
    lblMenu->setMaximumHeight(40);

    lblOrdine = new QLabel("Lista Ordini",this);
    lblOrdine->setStyleSheet("QLabel { font-size: 15px}");
    lblOrdine->setMaximumHeight(40);

    lblScontrino = new QLabel("Scontrino",this);
    lblScontrino->setStyleSheet("QLabel { font-size: 15px}");

    lblSconto = new QLabel(this);
    lblSconto->setMaximumHeight(40);
    lblSconto->setStyleSheet("QLabel { font-size: 15px}");
    lblSconto->hide();
    lblTotaleDesc = new QLabel("Totale parziale:",this);
    lblTotaleDesc->setStyleSheet("QLabel { font-size: 15px}");
    lblTotaleDesc->hide();
    lblTotaleEffettivoDesc = new QLabel("Totale effettivo:",this);
    lblTotaleEffettivoDesc->setStyleSheet("QLabel { font-size: 15px}");
    lblTotaleEffettivoDesc->hide();

    lblTotale = new QLabel("0.00 €",this);
    lblTotale->setStyleSheet("QLabel { font-size: 15px}");
    lblTotale->hide();

    lblTotaleEffettivo = new QLabel(this);
    lblTotaleEffettivo->setStyleSheet("QLabel { font-size: 15px}");
    lblTotaleEffettivo->hide();

    scrollAreaProdotti = new QScrollArea(this);
    scrollAreaOrdine = new QScrollArea(this);
    scrollAreaScontrino = new QScrollArea(this);
    scrollAreaProdotti->setMaximumWidth(450);
    scrollAreaOrdine->setMaximumWidth(450);
    scrollAreaScontrino->setMaximumWidth(450);
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

void View::setLblPortafoglioDati(QString s)
{
    zonaGestoreWidget->setLblPortafoglioDati(s);
}

View::View(QWidget *parent) : QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    topLayout = new QHBoxLayout();
    bottomLayout = new QHBoxLayout();
    menuLayout = new QVBoxLayout();
    prodottoSelezionatoLayout = new QVBoxLayout();
    ordineLayout = new QVBoxLayout();
    scontrinoLayout = new QVBoxLayout();
    labelTotaliLayout = new QHBoxLayout();
    labelTotaliDescrizioneLayout = new QHBoxLayout();
    bottoniOrdineLayout = new QHBoxLayout();

    //Zona Cliente
    zonaClienteWidget = new ZonaClienteWidget(this);
    zonaClienteWidget->setMaximumWidth(500);
    topLayout->addWidget(zonaClienteWidget);

    inizializzaInterfacciaOrdini();

    btnConfermaOrdine = new QPushButton("Conferma Ordine",this);
    btnConfermaOrdine->setEnabled(false);

    btnAnnullaOrdine = new QPushButton("Annulla Ordine",this);
    btnAnnullaOrdine->setEnabled(false);

    btnNuovoOrdine = new QPushButton("Nuovo Ordine",this);
    btnNuovoOrdine->setEnabled(false);

    mostraProdottoWidget = new MostraProdottoWidget(this);
    mostraProdottoWidget->setMinimumWidth(370);
    mostraProdottoWidget->setMaximumWidth(500);
    mostraProdottoWidget->setMaximumHeight(500);
    lblProdottoSelezionato = new QLabel("Prodotto selezionato:",this);
    QFont f("Arial", 15, QFont::DemiBold);
    lblProdottoSelezionato->setFont(f);
    lblProdottoSelezionato->setMaximumHeight(30);
    abilitaSceltaProdotto(false);

    msgErrori = new QMessageBox(this);

    zonaGestoreWidget = new ZonaGestoreWidget();
    zonaGestoreWidget->setMaximumSize(200,100);

    btnMostraGestore = new QPushButton("Mostra zona gestore",this);
    btnMostraGestore->setMaximumWidth(130);
    btnMostraGestore->setMaximumHeight(90);
    topLayout->addWidget(btnMostraGestore);
    topLayout->setAlignment(zonaClienteWidget,Qt::AlignLeft);
    topLayout->setAlignment(btnMostraGestore,Qt::AlignLeft);

    scontrinoLayout->addWidget(lblScontrino);
    scontrinoLayout->addWidget(scrollAreaScontrino);
    labelTotaliDescrizioneLayout->addWidget(lblTotaleDesc);
    labelTotaliDescrizioneLayout->addWidget(lblTotaleEffettivoDesc);
    labelTotaliLayout->addWidget(lblTotale);
    labelTotaliLayout->addWidget(lblTotaleEffettivo);
    scontrinoLayout->addLayout(labelTotaliDescrizioneLayout);
    scontrinoLayout->addLayout(labelTotaliLayout);
    scontrinoLayout->addWidget(lblSconto);
    scontrinoLayout->setAlignment(lblSconto,Qt::AlignRight);
    scontrinoLayout->setSpacing(10);

    ordineLayout->addWidget(lblOrdine);
    ordineLayout->addWidget(scrollAreaOrdine);
    bottoniOrdineLayout->addWidget(btnConfermaOrdine);
    bottoniOrdineLayout->addWidget(btnAnnullaOrdine);
    bottoniOrdineLayout->addWidget(btnNuovoOrdine);
    ordineLayout->addLayout(bottoniOrdineLayout);
    ordineLayout->setSpacing(10);

    prodottoSelezionatoLayout->addWidget(lblProdottoSelezionato);
    prodottoSelezionatoLayout->addWidget(mostraProdottoWidget);
    prodottoSelezionatoLayout->addSpacing(10);

    menuLayout->addWidget(lblMenu);
    menuLayout->addWidget(scrollAreaProdotti);
    menuLayout->setSpacing(10);

    bottomLayout->addLayout(menuLayout);
    bottomLayout->addLayout(prodottoSelezionatoLayout);
    bottomLayout->setAlignment(prodottoSelezionatoLayout,Qt::AlignTop);
    bottomLayout->addLayout(ordineLayout);
    bottomLayout->addLayout(scontrinoLayout);
    bottomLayout->setSpacing(30);

    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(bottomLayout);
    setLayout(mainLayout);

}

View::~View()
{
    delete listaProdotti;
    delete listaOrdini;
    delete listaScontrino;

    delete scrollAreaProdotti;
    delete lblMenu;
    delete menuLayout;

    delete mostraProdottoWidget;
    delete lblProdottoSelezionato;
    delete prodottoSelezionatoLayout;

    delete btnConfermaOrdine;
    delete btnAnnullaOrdine;
    delete btnNuovoOrdine;
    delete scrollAreaOrdine;
    delete lblOrdine;
    delete bottoniOrdineLayout;
    delete ordineLayout;

    delete scrollAreaScontrino;
    delete lblScontrino;
    delete lblTotale;
    delete lblTotaleDesc;
    delete lblTotaleEffettivo;
    delete lblTotaleEffettivoDesc;
    delete lblSconto;
    delete labelTotaliDescrizioneLayout;
    delete labelTotaliLayout;
    delete scontrinoLayout;

    delete zonaClienteWidget;
    delete zonaGestoreWidget;

    delete msgErrori;
    delete btnMostraGestore;

    delete bottomLayout;
    delete topLayout;
    delete mainLayout;
}


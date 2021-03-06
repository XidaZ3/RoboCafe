#include "Controller.h"

void Controller::setView(View *value)
{
    view = value;
    inizializzaClienteWidget();
    inizializzaMenu();
    inizializzaGestoreWidget();
}

void Controller::setModel(Model *value)
{
    model = value;
    readClientiFile();
    readMenuFromFile();
}

bool Controller::preparaOrdine()
{
    bool ret = false;
    try {
        if(model->getOrdineSize()>0)
        {
            float sconto=0;
            if(dynamic_cast<ClientePlus*>(model->getUtenteAttivo())){
                ClientePlus* clientePlus = static_cast<ClientePlus*>(model->getUtenteAttivo());
                sconto = 1-(clientePlus->getLivello()*0.05);
            }
            if(dynamic_cast<Dipendente*>(model->getUtenteAttivo())){
                sconto= Dipendente::sconto;
            }
            float totale = model->calcolaTotale();
            model->ritiroConto(sconto ? sconto*totale : totale);
            Risorse r=model->getRisorse();
            model->preparaOrdine(r);
            view->abilitaTotale(true);
            view->mostraTotale(totale);
            view->mostraTotaleEffettivo(sconto ? sconto*totale : totale);
            view->mostraSconto(sconto ? (1-sconto)*100 : 0);
            model->setRisorse(r);
            aggiornaStatoRisorse();
            ret = true;
        }
    }  catch (int e) {
        if(e==EccezioniCliente::CreditoInsufficiente){
            view->mostraErroreDialog("Il credito del cliente è insufficiente");
        }
    }
    return ret;
}

void Controller::inizializzaMenu()
{
    view->inizializzaListaProdotti(model->getProdotti());
}

void Controller::readMenuFromFile() const
{
    QString path("../RoboCafe/Controller/Files/menu.json");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly)){
        qWarning("Impossibile aprire il file");
        return;
    }
    QByteArray savedMenu = file.readAll();
    QJsonDocument menuDocument (QJsonDocument::fromJson(savedMenu));
    QJsonArray menu = menuDocument.array();
    for(auto i : menu){
        QJsonObject prodotto = i.toObject();
        if(prodotto.contains("te") && prodotto["te"].isObject())
        {
            Te* value = new Te();
            value->read(prodotto);
            model->aggiungiProdotto(value);
        }
        if(prodotto.contains("pizza") && prodotto["pizza"].isObject())
        {
            Pizza* value = new Pizza();
            value->read(prodotto);
            model->aggiungiProdotto(value);
        }
        if(prodotto.contains("caffe") && prodotto["caffe"].isObject())
        {
            Caffe* value = new Caffe();
            value->read(prodotto);
            model->aggiungiProdotto(value);
        }
    }
    file.close();
}

void Controller::writeMenuToFile() const
{
    QJsonObject prodotto;
    QJsonArray menu;
    Vettore<DeepPtr<Prodotto>> prodotti = model->getProdotti();
    for(auto i = prodotti.begin(); i != prodotti.end(); i++){
        prodotto = QJsonObject();
        (*i)->write(prodotto);
        menu.push_back(prodotto);
    }

    QJsonDocument doc(menu);
    QByteArray bytes = doc.toJson( QJsonDocument::Indented );
    QString path("../RoboCafe/Controller/Files/menu.json");
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        // qDebug() << "Opening file failed!";
        std::cout << "Fallito" << std::endl;
    }
    else
    {
        QTextStream stream(&file);
        stream.setCodec("utf-8");
        stream<<bytes;
        file.close();
    }

}

void Controller::writeClientiFile() const
{
    Vettore<DeepPtr<Cliente>> aux= model->getClientiDb();
    QJsonArray clientiDb;
    for(Vettore<DeepPtr<Cliente>>::iterator i = aux.begin();i!=aux.end();i++)
    {
        QJsonObject aux = (*i)->toQJsonObject();
        clientiDb.append(aux);
    }
    QJsonObject clienti;
    clienti.insert("clientiDb",clientiDb);
    QJsonDocument doc(clienti);
    QByteArray bytes = doc.toJson();
    QString path("../RoboCafe/Controller/Files/clienti.json");
    QFile file(path);

    if(!file.open(QIODevice::WriteOnly))
        std::cout << "Fallito" << std::endl;
    else
    {
        QTextStream stream(&file);
        stream.setCodec("utf-8");
        stream<<bytes;
        file.close();
    }
}

void Controller::readClientiFile() const
{
    QString path("../RoboCafe/Controller/Files/clienti.json");
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        qWarning("Impossibile aprire il file");
        return;
    }

    QByteArray byteArr = file.readAll();
    QJsonDocument doc (QJsonDocument::fromJson(byteArr));
    QJsonObject clientiDb = doc.object();

    if(clientiDb.contains("clientiDb") && clientiDb["clientiDb"].isArray())
    {
        QJsonArray arrClienti = clientiDb["clientiDb"].toArray();

        for(auto i : arrClienti)
        {
            QJsonObject cliente = i.toObject();
            if(cliente.contains("clienteStandard") && cliente["clienteStandard"].isObject())
            {
                ClienteStandard cs;
                cs.fromQJsonObject(cliente);
                model->aggiungiCliente(&cs);
            }
            if(cliente.contains("clientePlus") && cliente["clientePlus"].isObject())
            {
                ClientePlus cp;
                cp.fromQJsonObject(cliente);
                model->aggiungiCliente(&cp);
            }
            if(cliente.contains("dipendente") && cliente["dipendente"].isObject())
            {
                Dipendente dp;
                dp.fromQJsonObject(cliente);
                model->aggiungiCliente(&dp);
            }
        }
    }

    if(model->getClientiDb().getSize()!=0)
        model->setUtenteAttivo((&**model->getClientiDb().begin()));
    file.close();
}

void Controller::confermaOrdine()
{
    if(preparaOrdine()){
        view->inizializzaListaScontrino(model->getOrdini());
        view->inizializzaListaErrori(model->getErrori(),model->getOrdineSize());
        Cliente *c = model->getUtenteAttivo();
        int punti=0;
        if(dynamic_cast<ClientePlus*>(c))
            punti=static_cast<ClientePlus*>(c)->getPunti();
        view->aggiornaTransazione(c->getCredito(),model->getPortafoglio(),punti);
    }
    annullaOrdine();
    view->abilitaNuovoOrdine(true);
    view->abilitaAnnullamento(false);
    view->abilitaMenu(false);
    view->abilitaConfermaOrdine(false);
    view->abilitaCmbId(false);
    view->abilitaSceltaProdotto(false);
    view->inizializzaSceltaProdotto(nullptr);
}

void Controller::annullaOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(model->getOrdini());
    view->abilitaCmbId(true);
}

void Controller::rimuoviOrdine(int index)
{
    model->cancellaProdotto(index);
    if(model->getOrdini().getSize()==0){
        view->abilitaConfermaOrdine(false);
        view->abilitaAnnullamento(false);
        view->abilitaCmbId(true);
    }
    view->inizializzaListaOrdine(model->getOrdini());
}

void Controller::aggiungiOrdine(Prodotto* prodottoScelto)
{
    model->aggiungiOrdine(prodottoScelto);
    view->inizializzaSceltaProdotto(nullptr);
    if(model->getOrdini().getSize()==1){
        view->abilitaConfermaOrdine(true);
        view->abilitaNuovoOrdine(false);
        view->abilitaAnnullamento(true);
    }
    view->abilitaSceltaProdotto(false);
    view->inizializzaListaOrdine(model->getOrdini());
    view->abilitaCmbId(false);
}

void Controller::mostraSceltaProdotto(int index)
{
    view->abilitaSceltaProdotto(true);
    view->inizializzaSceltaProdotto(model->getProdottoAt(index)->clone());
}

void Controller::nuovoOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(model->getOrdini());
    view->inizializzaListaScontrino(model->getOrdini());
    view->abilitaTotale(false);
    view->abilitaNuovoOrdine(false);
    view->abilitaMenu(true);
    view->resetSceltaProdotto();
    view->abilitaCmbId(true);
    view->abilitaSceltaProdotto(false);
}

void Controller::upgradeLivello()const
{
    Cliente *c =model->getUtenteAttivo();
    if(dynamic_cast<ClientePlus*>(c))
    {
        try {
            model->upgradeLivello();
            ClientePlus *cp = static_cast<ClientePlus*>(c);
            view->clickUpgradeLivello(cp->getLivello(),cp->getPunti());
        }  catch (int e) {
            if(e==EccezioniCliente::PuntiInsufficienti)
                view->mostraErroreDialog("Punti insufficienti per il level up");
            if(e==EccezioniCliente::LivelloMassimo)
                view->mostraErroreDialog("Livello massimo raggiunto");
        }
    }
    else
        view->mostraErroreDialog("Level up solo per clienti plus");
}

void Controller::convertiPunti()const
{
    Cliente *c=model->getUtenteAttivo();
    if(dynamic_cast<ClientePlus*>(c))
    {
        try {
            static_cast<ClientePlus*>(c)->convertiPuntiCredito();
            view->clickConvertiPunti(c->getCredito());
        }  catch (int e) {
            if(e==EccezioniCliente::PuntiInsufficienti)
                view->mostraErroreDialog("Troppi pochi punti da convertire (necessari almeno 10)");
        }
    }
    else
        view->mostraErroreDialog("Solo clienti plus hanno punti da convertire");
}

void Controller::upgradeUtente() const
{
    Cliente *c=model->getUtenteAttivo();
    if(dynamic_cast<ClienteStandard*>(c))
    {
        try{
            model->upgradePlus();
            ClientePlus *cp=static_cast<ClientePlus*>(model->getUtenteAttivo());
            view->leggiCliente(cp);
            std::stringstream stream;
            stream << std::fixed << std::setprecision(2) <<model->getPortafoglio();
            view->setLblPortafoglioDati(QString::fromStdString(stream.str()));
        }catch(int e){
            if(e==EccezioniCliente::CreditoInsufficiente)
                view->mostraErroreDialog("Il credito del cliente è insufficiente");
        }

    }
    else
        //Qt non gestisce error handling su slots/signal
        view->mostraErroreDialog("Solo clienti standard possono fare upgrade");
}

void Controller::depositaCredito() const
{
    model->ricaricaCredito(view->getLneDepositaText().toFloat());
    Cliente *c=model->getUtenteAttivo();
    int punti=0;
    if(dynamic_cast<ClientePlus*>(c))
        punti=static_cast<ClientePlus*>(c)->getPunti();
    else
        punti=-1;
    if(c)
        view->clickDepositaCredito(c->getCredito(),punti);
}

void Controller::clienteSelezionato() const
{
    Cliente *c=model->cercaCliente(view->getCmbText().toInt());
    model->setUtenteAttivo(c);
    view->clickSelectCmb(model->getUtenteAttivo());

}

void Controller::creaUtente() const
{
    view->initCreazione();
}

void Controller::confermaUtente() const
{
    Cliente*c =nullptr;
    CreaUtenteWidget::tipoUtente aux = view->getTipoSelezionato();
    if(aux == CreaUtenteWidget::tipoUtente::standard)
    {
        ClienteStandard cs(model->getContaClienti()+1,view->getLneNomeCrea().toStdString(),view->getLneCognomeCrea().toStdString(),0);
        c=model->aggiungiCliente(&cs);
    }
    else if(aux == CreaUtenteWidget::tipoUtente::dipendente)
    {
        Dipendente dip(model->getContaClienti()+1,view->getLneNomeCrea().toStdString(),view->getLneCognomeCrea().toStdString(),0);
        c=model->aggiungiCliente(&dip);
    }
    else if(aux == CreaUtenteWidget::tipoUtente::plus)
    {
        ClientePlus cp(model->getContaClienti()+1,view->getLneNomeCrea().toStdString(),view->getLneCognomeCrea().toStdString(),0,0,1);
        c=model->aggiungiCliente(&cp);
    }

    model->setUtenteAttivo(c);
    view->aggiungiClienteCmb(c);
    view->leggiCliente(c);

    view->confermaCreazione(QString::fromStdString(std::to_string(model->getContaClienti()+1)));
    model->incrementaContaClienti();
}

void Controller::eliminaUtente() const
{
    if(model->getUtenteAttivo()!=nullptr)
    {
        int cmbValue =view->getCmbText().toInt();
        view->togliClienteCmb(QString::fromStdString(std::to_string(model->getUtenteAttivo()->getId())));
        model->cancellaCliente(cmbValue);
        view->leggiCliente(model->getUtenteAttivo());

    }
    else
        view->mostraErroreDialog("Non ci sono clienti da eliminare");
}

void Controller::confermaErrore() const
{
    view->confermaErrore();
}

void Controller::sloEnableView() const
{
    view->enableView(true);
}

void Controller::mostraZonaGestore() const
{
    view->zonaGestoreShow();
}

Controller::Controller(QObject *parent):QObject(parent)
{

}

Controller::~Controller()
{
    writeClientiFile();
}

void Controller::inizializzaClienteWidget() const{
    view->inizializzaClientiCmb(model->getClientiDb());
    view->leggiCliente(model->getUtenteAttivo());
}

void Controller::inizializzaGestoreWidget() const
{
    Risorse r=model->getRisorse();
    view->inizializzaGestore(model->getPortafoglio(),r.getLitriAcqua(),r.getCialdeCaffe(),r.getLitriLatte(),r.getFiltriTe(),r.getImpastiPizze());
}

void Controller::refillAcqua() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraAcqua();
    model->setRisorse(aux);
    view->clickAcqua(model->getRisorse().getLitriAcqua());
}

void Controller::refillCaffe() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraCaffe();
    model->setRisorse(aux);
    view->clickCaffe(model->getRisorse().getCialdeCaffe());
}

void Controller::refillLatte() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraLatte();
    model->setRisorse(aux);
    view->clickLatte(model->getRisorse().getLitriLatte());
}

void Controller::refillTe() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraTe();
    model->setRisorse(aux);
    view->clickTe(model->getRisorse().getFiltriTe());
}

void Controller::refillPizze() const
{
    Risorse aux =model->getRisorse();
    aux.rifornituraPizza();
    model->setRisorse(aux);
    view->clickPizze(model->getRisorse().getImpastiPizze());
}

void Controller::aggiornaStatoRisorse() const
{
    Risorse aux = model->getRisorse();
    view->clickPizze(aux.getImpastiPizze());
    view->clickAcqua(aux.getLitriAcqua());
    view->clickCaffe(aux.getCialdeCaffe());
    view->clickLatte(aux.getLitriLatte());
    view->clickTe(aux.getFiltriTe());
}

void Controller::prelevaPortafoglio() const
{
    try {
        model->prelevaPortafoglio(view->getLneCreditoText().toFloat());
        view->clickPreleva(model->getPortafoglio());
    }  catch (int e) {
        if(e==EccezioniModel::CreditoNonPrelevabile)
            view->mostraErroreDialog("Il credito selezionato non è prelevabile");
        if(e==EccezioniModel::CreditoNegativo)
            view->mostraErroreDialog("Il credito che si vuole prelevare è negativo");
    }
}



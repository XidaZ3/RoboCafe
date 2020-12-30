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
    //writeClientiFile();
    readClientiFile();
    model->setUtenteAttivo((&**(model->getClientiDb().begin())));
}

void Controller::preparaOrdine()
{

    if(model->getOrdineSize()>0)
    {
        Risorse r=model->getRisorse();
        float tot=model->preparaOrdine(r);
        view->mostraTotale(tot);
        model->setRisorse(r);
        aggiornaStatoRisorse();
        model->ritiroConto(tot);
    }

}

void Controller::inizializzaMenu()
{
    view->inizializzaListaProdotti(getProdotti());
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
}

void Controller::writeMenuToFile() const
{
    QJsonObject prodotto;
    QJsonArray menu;
    Vettore<Prodotto*> prodotti = getProdotti();
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
        std::cout << "FUNZIAAAA" << std::endl;
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
        QJsonObject cliente;
        string tipo="";
        QJsonObject aux = (*i)->toQJsonObject(tipo);
        cliente.insert(QString::fromStdString(tipo),aux);
        clientiDb.append(cliente);
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

        std::cout << "FUNZIAAAA" << std::endl;
        QTextStream stream(&file);
        stream.setCodec("utf-8");
        stream<<bytes;
        file.close();
    }
}

void Controller::readClientiFile() const
{
    QString path("../RoboCafe/Controller/Files/clienti.json");
    QFile clientiJson(path);
    if(!clientiJson.open(QIODevice::ReadOnly))
    {
        qWarning("Impossibile aprire il file");
        return;
    }

    QByteArray byteArr = clientiJson.readAll();
    QJsonDocument doc (QJsonDocument::fromJson(byteArr));
    QJsonObject clientiDb = doc.object();
    if(clientiDb.contains("clientiDb") && clientiDb["clientiDb"].isArray())
    {
        QJsonArray arrClienti = clientiDb["clientiDb"].toArray();
        // model->cancellaClienti();
        for(int index = 0; index < arrClienti.size(); index++)
        {
            QJsonObject dati, cliente = arrClienti[index].toObject();
            int id=0;
            string cognome="",nome="";
            float credito=0.0;
            int punti=0, livello=0;
            bool standard = false, plus =false, dipendente = false;

            if(cliente.contains("clienteStandard") && cliente["clienteStandard"].isObject())
            {
                dati =  cliente.value("clienteStandard").toObject();
                standard = true;
            }
            else if  (cliente.contains("clientePlus") && cliente["clientePlus"].isObject())
            {
                dati =  cliente.value("clientePlus").toObject();
                plus = true;
            }
            else if(cliente.contains("dipendente") && cliente["dipendente"].isObject())
            {
                dati =  cliente.value("dipendente").toObject();
                dipendente = true;
            }

            if(dati.contains("id") && dati["id"].isDouble())
                id = dati["id"].toInt();
            if(dati.contains("nome") && dati["nome"].isString())
                nome = dati.value("nome").toString().toStdString();
            if(dati.contains("cognome") && dati["cognome"].isString())
                cognome = dati["cognome"].toString().toStdString();
            if(dati.contains("credito") && dati["credito"].isDouble())
                credito = dati["credito"].toDouble();
            if(dati.contains("punti") && dati["punti"].isDouble())
                punti = dati["punti"].toInt();
            if(dati.contains("livello") && dati["livello"].isDouble())
                livello= dati["livello"].toDouble();

            if(plus)
                model->aggiungiCliente(new ClientePlus(id,nome,cognome,credito,punti,livello));
            if(standard)
                model->aggiungiCliente(new ClienteStandard(id,nome,cognome,credito));
            if(dipendente)
                model->aggiungiCliente(new Dipendente(id,nome,cognome,credito));
        }
    }

    // model->setUtenteAttivo((*model->getClientiDb().begin())->clone());
}

void Controller::confermaOrdine()
{
    preparaOrdine();
    view->inizializzaListaScontrino(getOrdini());
    view->inizializzaListaErrori(getErrori(),getOrdini().getSize());
    annullaOrdine();
    view->inizializzaListaOrdine(getOrdini());

    view->abilitaNuovoOrdine(true);
    view->abilitaAnnullamento(false);
    view->abilitaMenu(false);
    view->abilitaConfermaOrdine(false);
    view->abilitaCmbId(false);
    view->abilitaConfermaProdotto(false);

    Cliente *c = model->getUtenteAttivo();
    int punti=0;
    if(dynamic_cast<ClientePlus*>(c))
        punti=static_cast<ClientePlus*>(c)->getPunti();
    view->aggiornaTransazione(c->getCredito(),model->getPortafoglio(),punti);
}

void Controller::annullaOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(getOrdini());
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
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::aggiungiOrdine(Prodotto* prodottoScelto)
{
    model->aggiungiOrdine(prodottoScelto);
    if(model->getOrdini().getSize()==1){
        view->abilitaConfermaOrdine(true);
        view->abilitaNuovoOrdine(false);
        view->abilitaAnnullamento(true);
    }
    view->inizializzaListaOrdine(getOrdini());
    view->abilitaCmbId(false);
}

void Controller::mostraSceltaProdotto(int index)
{
    view->abilitaConfermaProdotto(true);
    view->inizializzaSceltaProdotto(model->getProdottoAt(index)->clone());
}

void Controller::nuovoOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(getOrdini());
    view->inizializzaListaScontrino(getOrdini());
    view->mostraTotale(0);
    view->abilitaNuovoOrdine(false);
    view->abilitaMenu(true);
    view->resetSceltaProdotto();
    view->abilitaCmbId(true);
    view->abilitaConfermaProdotto(false);
}

void Controller::upgradeLivello()const
{
    model->upgradeLivello();
    ClientePlus *cp = static_cast<ClientePlus*>(model->getUtenteAttivo());
    view->clickUpgradeLivello(cp->getLivello(),cp->getPunti());
}

void Controller::convertiPunti()const
{
    Cliente *c=model->getUtenteAttivo();
    if(dynamic_cast<ClientePlus*>(c))
    {
        static_cast<ClientePlus*>(c)->convertiPuntiCredito();
        view->clickConvertiPunti(c->getCredito());
        model->setUtenteAttivo(c);
    }
    else
        throw Eccezioni::ClienteNonPlus;
}

void Controller::upgradeUtente() const
{
    Cliente *c=model->getUtenteAttivo();
    if(dynamic_cast<ClienteStandard*>(c))
    {
        model->upgradePlus();
        ClientePlus *cp=static_cast<ClientePlus*>(model->getUtenteAttivo());
        view->leggiCliente(cp);
    }
    else
        throw Eccezioni::ClienteNonStandard;
}

void Controller::depositaCredito() const
{
    model->ricaricaCredito(view->getLneDepositaText().toFloat());
    Cliente *c=model->getUtenteAttivo();
    int punti=0;
    if(dynamic_cast<ClientePlus*>(c))
        punti=static_cast<ClientePlus*>(c)->getPunti();
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
    Cliente *c=nullptr, *last = &*(model->getClientiDb().back());
    //si potrebbe mettere un check

    CreaUtenteWidget::tipoUtente aux = view->getTipoSelezionato();
    if(aux == CreaUtenteWidget::tipoUtente::standard)
        c= new ClienteStandard(last->getId()+1,view->getLneNomeCrea().toStdString(),view->getLneCognomeCrea().toStdString(),0);
    else if(aux == CreaUtenteWidget::tipoUtente::dipendente)
        c= new Dipendente(last->getId()+1,view->getLneNomeCrea().toStdString(),view->getLneCognomeCrea().toStdString(),0);
    else if(aux == CreaUtenteWidget::tipoUtente::plus)
        c= new ClientePlus(last->getId()+1,view->getLneNomeCrea().toStdString(),view->getLneCognomeCrea().toStdString(),0,0,1);
    if(c)
    {
        model->aggiungiCliente(c);
        model->setUtenteAttivo(c);
        view->aggiungiClienteCmb(c);
        view->leggiCliente(c);
    }
    view->confermaCreazione(QString::fromStdString(std::to_string(last->getId()+1)));
}

void Controller::eliminaUtente() const
{
    model->cancellaCliente(view->getCmbText().toInt());
    view->togliClienteCmb(QString::fromStdString(std::to_string(model->getUtenteAttivo()->getId())));
    view->leggiCliente(model->getUtenteAttivo());
}

Vettore<Prodotto*> Controller::getProdotti() const
{
    auto vet = model->getProdotti();
    Vettore<Prodotto*> ret = Vettore<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
}

Vettore<Prodotto*> Controller::getOrdini() const
{
    auto vet = model->getOrdini();
    Vettore<Prodotto*> ret = Vettore<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
}

Vettore<Prodotto *> Controller::getErrori() const
{
    auto vet = model->getErrori();
    Vettore<Prodotto*> ret = Vettore<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
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
    model->prelevaPortafoglio(view->getLneCreditoText().toFloat());
    view->clickPreleva(model->getPortafoglio());
}



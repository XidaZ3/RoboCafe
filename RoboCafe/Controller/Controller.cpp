#include "Controller.h"
#include <Model/ClientePlus.h>
#include <Model/ClienteStandard.h>
#include <QTextStream>
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
    writeClienteFile();
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

void Controller::readMenuFromFile(string path)
{
    QFile menuJson(QString::fromStdString(path));
    if(!menuJson.open(QIODevice::ReadOnly)){
        qWarning("Impossibile aprire il file");
        return;
    }
    QByteArray savedMenu = menuJson.readAll();
    QJsonDocument menuDocument (QJsonDocument::fromJson(savedMenu));
    QJsonObject menu = menuDocument.object();
    if(menu.contains("menu") && menu["menu"].isArray()){
        QJsonArray arrMenu = menu["menu"].toArray();
        model->cancellaMenu();
        for(int index = 0; index < arrMenu.size(); ++index){
            QJsonObject prodotto = arrMenu[index].toObject();
            if(prodotto.contains("prodotto") && prodotto[""].isObject()){
                int idProdotto=0, calorie=0;
                string nome="",pathP="";
                float prezzo=0.0;
                Dimensione dim=Dimensione::Medio;
                if(prodotto.contains("idProdotto") && prodotto["idProdotto"].isDouble())
                    idProdotto = prodotto["idProdotto"].toInt();
                if(prodotto.contains("path") && prodotto["path"].isString())
                    pathP = prodotto["path"].toString().toStdString();
                if(prodotto.contains("nome") && prodotto["nome"].isString())
                    nome = prodotto["nome"].toString().toStdString();
                if(prodotto.contains("prezzo") && prodotto["prezzo"].isDouble())
                    prezzo = prodotto["prezzo"].toDouble();
                if(prodotto.contains("calorie") && prodotto["calorie"].isDouble())
                    calorie = prodotto["calorie"].toInt();
                if(prodotto.contains("dimensione") && prodotto["dimensione"].isDouble())
                    dim = Dimensione(prodotto["dimensione"].toInt());

                //Operazioni specifiche di Bevanda
                if(prodotto.contains("bevanda") && prodotto["bevanda"].isObject()){
                    float acqua=0.0;
                    bool ghiaccio=false;
                    if(prodotto.contains("acqua") && prodotto["acqua"].isDouble())
                        acqua = prodotto["acqua"].toDouble();
                    if(prodotto.contains("ghiaccio") && prodotto["ghiaccio"].isBool())
                        ghiaccio = prodotto["ghiaccio"].toBool();
                    if(prodotto.contains("Te") && prodotto["Te"].isString())
                    {
                        int filtriTe=0;
                        float latte=0.0;
                        bool limone=false;
                        if(prodotto.contains("filtriTe") && prodotto["filtriTe"].isDouble())
                            filtriTe = prodotto["filtriTe"].toInt();
                        if(prodotto.contains("latte") && prodotto["latte"].isDouble())
                            latte = prodotto["latte"].toDouble();
                        if(prodotto.contains("limone") && prodotto["limone"].isBool())
                            limone = prodotto["limone"].toBool();

                        model->aggiungiProdotto(new Te(idProdotto,pathP,nome,prezzo,acqua,calorie,dim,ghiaccio,latte,filtriTe,limone));
                    }
                    if(prodotto.contains("caffe") && prodotto["caffe"].isObject())
                    {
                        int cialdeCaffe=0;
                        float latte=0.0;
                        bool cacao=false,caramello=false;
                        if(prodotto.contains("cialdeCaffe") && prodotto["cialdeCaffe"].isDouble())
                            cialdeCaffe = prodotto["cialdeCaffe"].toInt();
                        if(prodotto.contains("latte") && prodotto["latte"].isDouble())
                            latte = prodotto["latte"].toDouble();
                        if(prodotto.contains("cacao") && prodotto["cacao"].isBool())
                            cacao = prodotto["cacao"].toBool();
                        if(prodotto.contains("caramello") && prodotto["caramello"].isBool())
                            caramello = prodotto["caramello"].toBool();

                        model->aggiungiProdotto(new Caffe(idProdotto,pathP,nome,prezzo,acqua,calorie,dim,ghiaccio,latte,cialdeCaffe,cacao,caramello));
                    }
                }
                if(prodotto.contains("panificato") && prodotto["panificato"].isObject()){
                    int temperatura=0;
                    if(prodotto.contains("temperatura") && prodotto["temperatura"].isDouble())
                        temperatura = prodotto["temperatura"].toInt();

                    if(prodotto.contains("pizza") && prodotto["pizza"].isObject())
                    {
                        bool extra=false;
                        if(prodotto.contains("extra") && prodotto["extra"].isBool())
                            extra = prodotto["extra"].toBool();

                        model->aggiungiProdotto(new Pizza(idProdotto,pathP,nome,prezzo,temperatura,calorie,extra));
                    }
                }
            }
        }
    }
}

void Controller::writeMenuToFile(string path)
{
    QFile menuJson(QString::fromStdString(path));
    if(!menuJson.open(QIODevice::WriteOnly)){
        qWarning("Impossibile aprire il file");
        return;
    }
    for(auto i= model->getProdotti().begin();i!=model->getProdotti().end();i++)
    {
        (*i)->toJsonString();
    }
}

void Controller::writeClienteFile() const
{
    QJsonObject cliente;
    QJsonArray recordsArray;
    cliente.insert("id",model->getUtenteAttivo()->getId());
    cliente.insert("nome",QString::fromStdString(model->getUtenteAttivo()->getNome()));
    cliente.insert("cognome",QString::fromStdString(model->getUtenteAttivo()->getCognome()));
    cliente.insert("credito",model->getUtenteAttivo()->getCredito());

    recordsArray.push_back(cliente);
    QJsonDocument doc(cliente);
    QByteArray bytes = doc.toJson( QJsonDocument::Indented );
    QDir dir;
    //std::cout<< dir.setCurrent("..")<<std::endl;
    QString path("../RoboCafe/Controller/Files/clienti.json");
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
    {
        std::cout<<"entrato";
        throw Eccezioni::ClienteNonStandard;
    }
}

void Controller::depositaCredito() const
{
    model->ricaricaCredito(view->getLneDepositaText().toFloat());
    Cliente *c=model->getUtenteAttivo();
    int punti=0;
    if(dynamic_cast<ClientePlus*>(c))
        punti=static_cast<ClientePlus*>(c)->getPunti();
    view->clickDepositaCredito(c->getCredito(),punti);
}

void Controller::clienteSelezionato() const
{
    Cliente *c=model->cercaCliente(view->getCmbText().toInt());
    model->setUtenteAttivo(c);
    view->clickSelectCmb(model->getUtenteAttivo());

}

Vettore<Prodotto*> Controller::getProdotti()
{
    auto vet = model->getProdotti();
    Vettore<Prodotto*> ret = Vettore<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
}

Vettore<Prodotto*> Controller::getOrdini()
{
    auto vet = model->getOrdini();
    Vettore<Prodotto*> ret = Vettore<Prodotto*>();
    for(auto i =vet.begin();i!= vet.end(); i++)
    {
        ret.push_back((**i).clone());
    }
    return ret;
}

Vettore<Prodotto *> Controller::getErrori()
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


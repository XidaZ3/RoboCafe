#include "Controller.h"
#include <Model/ClientePlus.h>
#include <Model/ClienteStandard.h>

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
}

void Controller::preparaOrdine()
{
    if(model->getOrdineSize()>0)
    {
        Risorse r=model->getRisorse();
        view->mostraTotale(model->preparaOrdine(r));
        model->setRisorse(r);
        aggiornaStatoRisorse();
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
            if(prodotto.contains("Te") && prodotto["Te"].isString())
            {
                int idProdotto, quantita, filtriTe;
                string nome;
                float acqua, latte;
                bool limone, ghiaccio;
                if(prodotto.contains("idProdotto") && prodotto["idProdotto"].isDouble())
                    idProdotto = prodotto["idProdotto"].toInt();
                if(prodotto.contains("quantita") && prodotto["quantita"].isDouble())
                    quantita = prodotto["quantita"].toInt();
                if(prodotto.contains("filtriTe") && prodotto["filtriTe"].isDouble())
                    filtriTe = prodotto["filtriTe"].toInt();
                if(prodotto.contains("acqua") && prodotto["acqua"].isDouble())
                    acqua = prodotto["acqua"].toDouble();
                if(prodotto.contains("latte") && prodotto["latte"].isDouble())
                    latte = prodotto["latte"].toDouble();
                if(prodotto.contains("ghiaccio") && prodotto["ghiaccio"].isBool())
                    ghiaccio = prodotto["ghiaccio"].toBool();
                if(prodotto.contains("limone") && prodotto["limone"].isBool())
                    limone = prodotto["limone"].toBool();
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
        (*i)->toString();
    }
}

void Controller::confermaOrdine()
{
    preparaOrdine();
    view->inizializzaListaScontrino(getOrdini());
    annullaOrdine();
    view->inizializzaListaOrdine(getOrdini());

    view->abilitaNuovoOrdine(true);
    view->abilitaAnnullamento(false);
    view->abilitaMenu(false);
    view->abilitaConferma(false);
}

void Controller::annullaOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::rimuoviOrdine(int index)
{
    model->cancellaProdotto(index);
    if(model->getOrdini().getSize()==0){
        view->abilitaConferma(false);
        view->abilitaAnnullamento(false);
    }
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::aggiungiOrdine(int index)
{
    model->aggiungiOrdine(index);
    if(model->getOrdini().getSize()==1){
        view->abilitaConferma(true);
        view->abilitaNuovoOrdine(false);
        view->abilitaAnnullamento(true);
    }
    view->inizializzaListaOrdine(getOrdini());
}

void Controller::nuovoOrdine()
{
    model->cancellaOrdine();
    view->inizializzaListaOrdine(getOrdini());
    view->inizializzaListaScontrino(getOrdini());
    view->mostraTotale(0);
    view->abilitaNuovoOrdine(false);
    view->abilitaMenu(true);
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
    {
        std::cout<<"entrato";
        throw Eccezioni::ClienteNonPlus;
    }
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
    Cliente *c=model->getUtenteAttivo();
    c->Ricarica(view->getLneDepositaText().toFloat());
    view->clickDepositaCredito(c->getCredito());
    model->setUtenteAttivo(c);
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


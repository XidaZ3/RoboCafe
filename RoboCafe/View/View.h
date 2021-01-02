#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QScrollArea>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QStringList>
#include <QDialog>
#include <QMessageBox>
#include "Model/ClientePlus.h"
#include "ProdottoItemWidget.h"
#include "OrdineItemWidget.h"
#include "ScontrinoItemWidget.h"
#include "CustomListWidget.h"
#include "MostraProdottoWidget.h"
#include "ZonaClienteWidget.h"
#include "ZonaGestoreWidget.h"
#include "CreaUtenteWidget.h"
#include "ErroreWidget.h"
#include<string>
using std::string;
#include <iomanip>
#include <sstream>

//da eliminare
#include "Model/Vettore.h"
#include "Model/Te.h"
#include "Model/DeepPtr.h"

class Controller;

class View : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    CustomListWidget<ProdottoItemWidget*>* listaProdotti;
    CustomListWidget<OrdineItemWidget*>* listaOrdini;
    CustomListWidget<ScontrinoItemWidget*>* listaScontrino;
    QScrollArea* scrollAreaProdotti;
    QScrollArea* scrollAreaOrdine;
    QScrollArea* scrollAreaScontrino;

    QLabel* lblMenu;
    QLabel* lblOrdine;
    QLabel* lblScontrino;
    QLabel* lblTotaleDesc;
    QLabel* lblTotale;
    QLabel* lblTotaleEffettivoDesc;
    QLabel* lblTotaleEffettivo;
    QLabel* lblSconto;

    QMessageBox* msgErrori;

    MostraProdottoWidget *mostraProdottoWidget;
    ZonaClienteWidget *zonaClienteWidget;
    ZonaGestoreWidget *zonaGestoreWidget;
    QPushButton *btnMostraGestore;
    CreaUtenteWidget *creaUtenteWidget;
    ErroreWidget *erroreWidget;
    QPushButton* btnConfermaOrdine;
    QPushButton* btnAnnullaOrdine;
    QPushButton* btnNuovoOrdine;
    QPushButton *btnOkCreazione;
    void inizializzaInterfacciaOrdini();
public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    void setController(Controller *value);
    void inizializzaListaProdotti(Vettore<DeepPtr<Prodotto>> prodotti);
    void inizializzaListaOrdine(Vettore<DeepPtr<Prodotto>> prodotti);
    void inizializzaListaScontrino(Vettore<DeepPtr<Prodotto>> prodotti);
    void inizializzaListaErrori(Vettore<DeepPtr<Prodotto>> prodotti, int startIndex);
    void inizializzaSceltaProdotto(Prodotto* prodotto);
    void resetSceltaProdotto();
    void abilitaCmbId(bool value);
    void abilitaConfermaOrdine(bool value);
    void abilitaAnnullamento(bool value);
    void abilitaNuovoOrdine(bool value);
    void abilitaMenu(bool value);
    void abilitaConfermaProdotto(bool value);
    void mostraTotale(float value);
    void mostraTotaleEffettivo(float value);
    void mostraSconto(float value);
    void abilitaTotale(bool value);
    void aggiornaTransazione(float credito, float portafoglio, int punti);
    void inizializzaClientiCmb(Vettore<DeepPtr<Cliente>> vet);
    void aggiungiClienteCmb(Cliente *c);
    void togliClienteCmb(QString s);
    void leggiCliente(Cliente *cliente);
    void inizializzaGestore(int portafoglio=0,float acqua=0, int caffe=0, float latte=0, int te=0, int pizze =0);
    void initCreazione();
    void confermaCreazione(QString s);
    void mostraErroreDialog(QString messaggio);
    void confermaErrore();

    void clickAcqua(float acqua);
    void clickCaffe(int caffe);
    void clickLatte(float latte);
    void clickTe(int te);
    void clickPizze(int pizze);
    void clickPreleva(float credito);

    void clickUpgradeLivello(int livello,int punti);
    void clickConvertiPunti(float credito);
    void clickDepositaCredito(float credito,int punti);
    void clickSelectCmb(Cliente *c);

    CreaUtenteWidget::tipoUtente getTipoSelezionato() const;
    QString getLneCreditoText()const;
    QString getLneDepositaText()const;
    QString getCmbText() const;
    QString getLneNomeCrea() const;
    QString getLneCognomeCrea() const;
    void enableView(bool b);
    void zonaGestoreShow() const;
};

#endif // VIEW_H

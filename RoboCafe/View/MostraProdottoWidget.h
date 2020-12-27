#ifndef MOSTRAPRODOTTOWIDGET_H
#define MOSTRAPRODOTTOWIDGET_H
#include <QWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QGroupBox>
#include "Model/Prodotto.h"
#include "Model/Te.h"
#include "Model/Caffe.h"
#include "Model/Pizza.h"

class MostraProdottoWidget:public QWidget
{
    Q_OBJECT
private:
    Prodotto* prodotto;
    // Pizza: Dimensione, temperatura (int), extra (bool)
    // Te: Dimensione, Acqua, ghiaccio (bool), latte (float), filtri (int), limone (bool)
    // Caffe: Dimensione, Acqua, ghiaccio (bool), latte (float), cialde (int), cacao  (bool), caramello  (bool)
    QVBoxLayout *mainLayout;
    QHBoxLayout *descrizioneLayout;
    QVBoxLayout *lblLayout;
    QHBoxLayout *rdoLayout;
    QHBoxLayout *boolChoiceOneLayout;
    QHBoxLayout *boolChoiceTwoLayout;
    QHBoxLayout *boolChoiceThreeLayout;
    QHBoxLayout *spbLayout;

    QGroupBox *grbBoolChoiceOne;
    QGroupBox *grbBoolChoiceTwo;
    QGroupBox *grbBoolChoiceThree;
    QGroupBox *grbIntChoiceOne;

    //Visualizzazione info generali
    QLabel *lblProdotto;
    QLabel *lblCosto;
    QLabel *lblCostoDati;
    QLabel *lblCalorie;
    QLabel *lblCalorieDati;
    QFrame *frmImmagine;

    //Scelta dimensione
    QLabel *lblQuantita;
    QRadioButton *rdoGrande;
    QRadioButton *rdoMedia;
    QRadioButton *rdoPiccolo;

    //Scelta booleana 1
    QLabel *lblBoolChoiceOne;
    QRadioButton *rdoBoolChoiceOneTrue;
    QRadioButton *rdoBoolChoiceOneFalse;

    //Scelta booleana 2
    QLabel *lblBoolChoiceTwo;
    QRadioButton *rdoBoolChoiceTwoTrue;
    QRadioButton *rdoBoolChoiceTwoFalse;

    //Scelta booleana 3
    QLabel *lblBoolChoiceThree;
    QRadioButton *rdoBoolChoiceThreeTrue;
    QRadioButton *rdoBoolChoiceThreeFalse;

    //Scelta intera 1
    QLabel *lblIntChoiceOne;
    QSpinBox *spbIntChoiceOne;


    QPushButton *btnConferma;
    void addBoolChoiceOne();
    void addBoolChoiceTwo();
    void addBoolChoiceThree();
    void addIntChoiceOne();

public:
    MostraProdottoWidget(QWidget *parent=nullptr);
    void setProdotto(Prodotto *value);
    void setInterfacciaPizza();
    void setInterfacciaTe();
    void setInterfacciaCaffe();
    void resetInterfaccia();
    void btnConfermaEnabled(bool value);

    QPushButton *getBtnConferma() const;

public slots:
    void btnTriggered();

signals:
    void conferma(Prodotto* prodotto);
};

#endif // MOSTRAPRODOTTOWIDGET_H

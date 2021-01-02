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
#include <QPixmap>
#include "Model/Prodotto.h"
#include "Model/Te.h"
#include "Model/Caffe.h"
#include "Model/Pizza.h"

class MostraProdottoWidget:public QWidget
{
    Q_OBJECT
private:
    //Prodotto da visualizzare
    Prodotto* prodotto;

    //Layout utilizzati dalle varie scelte e dal widget
    QVBoxLayout *mainLayout;
    QHBoxLayout *descrizioneLayout;
    QVBoxLayout *lblLayout;
    QHBoxLayout *rdoLayout;
    QHBoxLayout *boolChoiceOneLayout;
    QHBoxLayout *boolChoiceTwoLayout;
    QHBoxLayout *boolChoiceThreeLayout;
    QHBoxLayout *spbLayout;

    //Groupboxes per contenere le scelte
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
    QLabel *lblImmagine;

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

    //Bottone di conferma per la scelta
    QPushButton *btnConferma;

    void addBoolChoiceOne();
    void addBoolChoiceTwo();
    void addBoolChoiceThree();
    void addIntChoiceOne();
    void setInterfacciaPizza();
    void setInterfacciaTe();
    void setInterfacciaCaffe();

public:
    MostraProdottoWidget(QWidget *parent=nullptr);
    void setProdotto(Prodotto *value);
    void resetInterfaccia();
    void btnConfermaEnabled(bool value);
    QPushButton *getBtnConferma() const;

public slots:
    void btnTriggered();

signals:
    void conferma(Prodotto* prodotto);
};

#endif // MOSTRAPRODOTTOWIDGET_H

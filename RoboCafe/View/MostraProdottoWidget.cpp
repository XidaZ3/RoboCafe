#include "MostraProdottoWidget.h"

#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

MostraProdottoWidget::MostraProdottoWidget(QWidget *parent):QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *descrizioneLayout = new QHBoxLayout();
    QVBoxLayout *lblLayout = new QVBoxLayout();
    QHBoxLayout *rdoLayout = new QHBoxLayout();
//    QHBoxLayout *inputLayout = new QHBoxLayout();
//    QHBoxLayout *frameLayout = new QHBoxLayout();
//    QVBoxLayout *lblLayout = new QVBoxLayout();
//    QVBoxLayout *dataLayout = new QVBoxLayout();
//    QVBoxLayout *btnLayout = new QVBoxLayout();
//    QHBoxLayout *lvlLayout = new QHBoxLayout();

    QLabel *lblProdotto = new QLabel("Prodotto selezionato:",this);
    lblProdotto->setStyleSheet("background-color: rgb(200,150,200)");
    QFont f("Arial", 15, QFont::DemiBold);
    lblProdotto->setFont(f);

    QLabel *lblCosto = new QLabel("Costo:",this);
    QLabel *lblCostoDati = new QLabel("12,34",this);
    QLabel *lblCalorie = new QLabel("Calorie:",this);
    QLabel *lblCalorieDati = new QLabel("671kcal",this);

    QFrame *frmImmagine= new QFrame(this);

    QLabel *lblQuantita = new QLabel("Quantità:",this);
    QRadioButton *rdoGrande = new QRadioButton("Grande",this);
    QRadioButton *rdoMedia = new QRadioButton("Medio",this);
    QRadioButton *rdoPiccolo = new QRadioButton("Piccolo",this);

    QPushButton *btnConferma= new QPushButton("Conferma scelta",this);

    lblLayout->addWidget(lblCosto);
    lblLayout->addWidget(lblCostoDati);
    lblLayout->addWidget(lblCalorie);
    lblLayout->addWidget(lblCalorieDati);

    descrizioneLayout->addLayout(lblLayout);
    descrizioneLayout->addWidget(frmImmagine);

    rdoLayout->addWidget(lblQuantita);
    rdoLayout->addWidget(rdoPiccolo);
    rdoLayout->addWidget(rdoMedia);
    rdoLayout->addWidget(rdoGrande);

    mainLayout->addWidget(lblProdotto);
    mainLayout->addLayout(descrizioneLayout);
    mainLayout->addLayout(rdoLayout);
    mainLayout->addWidget(btnConferma);

    setStyleSheet("background-color: rgb(200,150,200)");
}

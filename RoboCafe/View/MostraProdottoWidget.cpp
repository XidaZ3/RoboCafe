#include "MostraProdottoWidget.h"

MostraProdottoWidget::MostraProdottoWidget(QWidget *parent):QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);
    descrizioneLayout = new QHBoxLayout();
    lblLayout = new QVBoxLayout();
    rdoLayout = new QHBoxLayout();

    lblProdotto = new QLabel("Prodotto selezionato:",this);
    lblProdotto->setStyleSheet("background-color: rgb(200,150,200)");
    QFont f("Arial", 15, QFont::DemiBold);
    lblProdotto->setFont(f);

    lblCosto = new QLabel("Costo:",this);
    lblCostoDati = new QLabel("12,34",this);
    lblCalorie = new QLabel("Calorie:",this);
    lblCalorieDati = new QLabel("671kcal",this);

    frmImmagine= new QFrame(this);

    lblQuantita = new QLabel("Quantità:",this);
    rdoGrande = new QRadioButton("Grande",this);
    rdoMedia = new QRadioButton("Medio",this);
    rdoPiccolo = new QRadioButton("Piccolo",this);

    btnConferma= new QPushButton("Conferma scelta",this);

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

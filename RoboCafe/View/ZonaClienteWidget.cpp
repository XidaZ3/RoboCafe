#include "ZonaClienteWidget.h"

ZonaClienteWidget::ZonaClienteWidget(QWidget *parent): QWidget(parent)
{
    frmCliente = new QFrame(this);
    //frmCliente->setMaximumSize(400,400);
    lblCliente = new QLabel("Cliente:",this);
    lblCliente->setStyleSheet("background-color: rgb(200,150,200)");
    QFont f("Arial", 20, QFont::Bold);
    lblCliente->setFont(f);

    mainLayout = new QVBoxLayout(this);

    inputLayout = new QHBoxLayout();
    frameLayout = new QHBoxLayout();
    lblLayout = new QVBoxLayout();
    dataLayout = new QVBoxLayout();
    btnLayout = new QVBoxLayout();
    lvlLayout = new QHBoxLayout();

    lblNome = new QLabel("Nome:",frmCliente);
    lblCognome = new QLabel("Cognome:",frmCliente);
    lblCredito = new QLabel("Credito:",frmCliente);
    lblPunti = new QLabel("Punti:",frmCliente);
    lblLivello = new QLabel("Livello:",frmCliente);
    lblLivelloEff = new QLabel("0",frmCliente);

    cmbNome = new QComboBox(frmCliente);
    lneCognome = new QLineEdit(frmCliente);
    lneCredito = new QLineEdit(frmCliente);
    lnePunti = new QLineEdit(frmCliente);
    prgLivello = new QProgressBar(frmCliente);

    btnUpgrade = new QPushButton("Upgrade Utente",this);
    btnLevelUp = new QPushButton("Level Up",this);
    btnConverti = new QPushButton("Converti punti a credito",this);

    lblLayout->addWidget(lblNome);
    lblLayout->addWidget(lblCognome);
    lblLayout->addWidget(lblCredito);
    lblLayout->addWidget(lblPunti);
    lblLayout->addWidget(lblLivello);

    dataLayout->addWidget(cmbNome);
    dataLayout->addWidget(lneCognome);
    dataLayout->addWidget(lneCredito);
    dataLayout->addWidget(lnePunti);

    lvlLayout->addWidget(lblLivelloEff);
    lvlLayout->addWidget(prgLivello);

    dataLayout->addLayout(lvlLayout);

    btnLayout->addWidget(btnUpgrade);
    btnLayout->addWidget(btnLevelUp);
    btnLayout->addWidget(btnConverti);

    frmCliente->setLayout(frameLayout);
    frameLayout->addLayout(lblLayout);
    frameLayout->addLayout(dataLayout);

    inputLayout->addWidget(frmCliente);
    inputLayout->addLayout(btnLayout);

    mainLayout->addWidget(lblCliente);
    mainLayout->addLayout(inputLayout);

    setStyleSheet("background-color: rgb(200,150,200)");
    frmCliente->setStyleSheet("background-color: rgb(200,200,200)");
}

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

    lblId = new QLabel("Id:",frmCliente);
    lblNome = new QLabel("Nome:",frmCliente);
    lblCognome = new QLabel("Cognome:",frmCliente);
    lblCredito = new QLabel("Credito:",frmCliente);
    lblPunti = new QLabel("Punti:",frmCliente);
    lblLivello = new QLabel("Livello:",frmCliente);
    lblLivelloEff = new QLabel("0",frmCliente);

    cmbId = new QComboBox(frmCliente);
    lneNome = new QLineEdit(frmCliente);
    lneNome->setDisabled(true);
    lneCognome = new QLineEdit(frmCliente);
    lneCognome->setDisabled(true);
    lneCredito = new QLineEdit(frmCliente);
    lneCredito->setDisabled(true);
    lnePunti = new QLineEdit(frmCliente);
    lnePunti->setDisabled(true);
    prgLivello = new QProgressBar(frmCliente);

    btnUpgrade = new QPushButton("Upgrade Utente",this);
    btnLevelUp = new QPushButton("Level Up",this);
    btnConverti = new QPushButton("Converti punti a credito",this);

    lblLayout->addWidget(lblId);
    lblLayout->addWidget(lblNome);
    lblLayout->addWidget(lblCognome);
    lblLayout->addWidget(lblCredito);
    lblLayout->addWidget(lblPunti);
    lblLayout->addWidget(lblLivello);

    dataLayout->addWidget(cmbId);
    dataLayout->addWidget(lneNome);
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

void ZonaClienteWidget::addCmbId(QString s)
{
    cmbId->addItem(s);
}

void ZonaClienteWidget::setLneNome(QString s)
{
     lneNome->setText(s);
}

void ZonaClienteWidget::setLneCognome(QString s)
{
    lneCognome->setText(s);
}
void ZonaClienteWidget::setLneCredito(QString s)
{
    lneCredito->setText(s);
}
void ZonaClienteWidget::setLnePunti(QString s)
{
    lnePunti->setText(s);
}
void ZonaClienteWidget::setPrgLivello(int punti)
{
    prgLivello->setRange(0,100);
    if(punti > 100)
        prgLivello->setValue(100);
    else
        prgLivello->setValue(punti);
}

void ZonaClienteWidget::setLblLivelloEff(QString s)
{
    lblLivelloEff->setText(s);
}

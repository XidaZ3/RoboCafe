#include "ZonaClienteWidget.h"

QPushButton *ZonaClienteWidget::getBtnUpgrade() const
{
    return btnUpgrade;
}

QPushButton *ZonaClienteWidget::getBtnLevelUp() const
{
    return btnLevelUp;
}

QPushButton *ZonaClienteWidget::getBtnConverti() const
{
    return btnConverti;
}

QPushButton *ZonaClienteWidget::getBtnDeposita() const
{
    return btnDeposita;
}


QComboBox *ZonaClienteWidget::getCmbId() const
{
    return cmbId;
}

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
    lblCreditoEff = new QLabel("0",frmCliente);
    lblPuntiEff = new QLabel("0",frmCliente);
    prgLivello = new QProgressBar(frmCliente);

    btnUpgrade = new QPushButton("Upgrade Utente",this);
    btnLevelUp = new QPushButton("Level Up",this);
    btnConverti = new QPushButton("Converti punti a credito",this);
    lblDeposita = new QLabel("Credito da ricaricare:",this);
    lneDeposita = new QLineEdit(this);
    btnDeposita = new QPushButton("Deposita",this);

    lblLayout->addWidget(lblId);
    lblLayout->addWidget(lblNome);
    lblLayout->addWidget(lblCognome);
    lblLayout->addWidget(lblCredito);
    lblLayout->addWidget(lblPunti);
    lblLayout->addWidget(lblLivello);

    dataLayout->addWidget(cmbId);
    dataLayout->addWidget(lneNome);
    dataLayout->addWidget(lneCognome);
    dataLayout->addWidget(lblCreditoEff);
    dataLayout->addWidget(lblPuntiEff);

    lvlLayout->addWidget(lblLivelloEff);
    lvlLayout->addWidget(prgLivello);

    dataLayout->addLayout(lvlLayout);

    btnLayout->addWidget(btnUpgrade);
    btnLayout->addWidget(btnLevelUp);
    btnLayout->addWidget(btnConverti);
    btnLayout->addWidget(lblDeposita);
    btnLayout->addWidget(lneDeposita);
    btnLayout->addWidget(btnDeposita);

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

void ZonaClienteWidget::addCmbId(QString s)const
{
    cmbId->addItem(s);
}

void ZonaClienteWidget::setCmbEnabled(bool e)
{
    cmbId->setEnabled(e);
}

void ZonaClienteWidget::setLneNome(QString s)const
{
     lneNome->setText(s);
}

void ZonaClienteWidget::setLneCognome(QString s)const
{
    lneCognome->setText(s);
}
void ZonaClienteWidget::setLblCreditoEff(QString s)const
{
    lblCreditoEff->setText(s);
}
void ZonaClienteWidget::setLblPuntiEff(QString s)const
{
    lblPuntiEff->setText(s);
}
void ZonaClienteWidget::setPrgLivello(int punti)const
{
    prgLivello->setRange(0,100);
    if(punti > 100)
        prgLivello->setValue(100);
    else
        prgLivello->setValue(punti);
}

void ZonaClienteWidget::setLneDepositaText(QString s)const
{
    lneDeposita->setText(s);
}

QString ZonaClienteWidget::getLneDepositaText() const
{
    return lneDeposita->text();
}

QString ZonaClienteWidget::getCmbText() const
{
    return cmbId->currentText();
}

void ZonaClienteWidget::setLblLivelloEff(QString s)const
{
    lblLivelloEff->setText(s);
}

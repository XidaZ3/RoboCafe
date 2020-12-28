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

QPushButton *ZonaClienteWidget::getBtnCrea() const
{
    return btnCrea;
}

ZonaClienteWidget::ZonaClienteWidget(QWidget *parent): QWidget(parent)
{
    frmCliente = new QFrame(this);
    lblCliente = new QLabel("Cliente:",this);
    QFont f("Arial", 20, QFont::Bold);
    lblCliente->setFont(f);

    mainLayout = new QVBoxLayout(this);
    inputLayout = new QHBoxLayout();
    frameLayout = new QVBoxLayout();
    idLayout = new QHBoxLayout();
    nomeLayout = new QHBoxLayout();
    cognomeLayout = new QHBoxLayout();
    creditoLayout = new QHBoxLayout();
    puntiLayout = new QHBoxLayout();
    lvlLayout = new QHBoxLayout();
    //    lblLayout = new QVBoxLayout();
    //    dataLayout = new QVBoxLayout();
    btnLayout = new QVBoxLayout();
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
    lneNome->setMaximumWidth(95);
    lneCognome = new QLineEdit(frmCliente);
    lneCognome->setDisabled(true);
    lneCognome->setMaximumWidth(95);
    lblCreditoEff = new QLabel("0",frmCliente);
    lblPuntiEff = new QLabel("0",frmCliente);
    prgLivello = new QProgressBar(frmCliente);

    btnCrea = new QPushButton("Crea utente",this);
    btnUpgrade = new QPushButton("Upgrade Utente",this);
    btnLevelUp = new QPushButton("Level Up",this);
    btnConverti = new QPushButton("Converti punti a credito",this);
    lblDeposita = new QLabel("Credito da ricaricare:",this);
    lneDeposita = new QLineEdit(this);
    btnDeposita = new QPushButton("Deposita",this);

    idLayout->addWidget(lblId);
    idLayout->addWidget(cmbId);
    nomeLayout->addWidget(lblNome);
    nomeLayout->addWidget(lneNome);
    cognomeLayout->addWidget(lblCognome);
    cognomeLayout->addWidget(lneCognome);
    creditoLayout->addWidget(lblCredito);
    creditoLayout->addWidget(lblCreditoEff);
    puntiLayout->addWidget(lblPunti);
    puntiLayout->addWidget(lblPuntiEff);
    lvlLayout->addWidget(lblLivello);
    lvlLayout->addWidget(lblLivelloEff);
    lvlLayout->addWidget(prgLivello);

    btnLayout->addWidget(btnCrea);
    btnLayout->addWidget(btnUpgrade);
    btnLayout->addWidget(btnLevelUp);
    btnLayout->addWidget(btnConverti);
    btnLayout->addWidget(lblDeposita);
    btnLayout->addWidget(lneDeposita);
    btnLayout->addWidget(btnDeposita);

    frmCliente->setLayout(frameLayout);
    frameLayout->addLayout(idLayout);
    frameLayout->addLayout(nomeLayout);
    frameLayout->addLayout(cognomeLayout);
    frameLayout->addLayout(creditoLayout);
    frameLayout->addLayout(puntiLayout);
    frameLayout->addLayout(lvlLayout);

    inputLayout->addWidget(frmCliente);
    inputLayout->addLayout(btnLayout);

    mainLayout->addWidget(lblCliente);
    mainLayout->addLayout(inputLayout);
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

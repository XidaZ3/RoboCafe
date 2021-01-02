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

void ZonaClienteWidget::setBtnCrea(QPushButton *value)
{
    btnCrea = value;
}

QPushButton *ZonaClienteWidget::getBtnElimina() const
{
    return btnElimina;
}

ZonaClienteWidget::~ZonaClienteWidget()
{
    delete lblCliente;
    delete lblId;
    delete lblNome;
    delete lblCognome;
    delete lblCredito;
    delete lblPunti;
    delete lblLivello;
    delete lblLivelloEff;
    delete cmbId;
    delete lneNome;
    delete lneCognome;
    delete lblCreditoEff;
    delete lblPuntiEff;
    delete prgLivello;
    delete btnCrea;
    delete btnUpgrade;
    delete btnLevelUp;
    delete btnConverti;
    delete lblDeposita;
    delete lneDeposita;
    delete btnDeposita;
    delete btnElimina;


    delete idLayout;
    delete nomeLayout;
    delete cognomeLayout;
    delete creditoLayout;
    delete puntiLayout;
    delete lvlLayout;
    delete btnLayout;
    delete btn2Layout;
     delete frameLayout;
    delete frmCliente;
    delete inputLayout;
    delete mainLayout;
}

ZonaClienteWidget::ZonaClienteWidget(QWidget *parent): QWidget(parent)
{
    frmCliente = new QFrame(this);
    lblCliente = new QLabel("Cliente:",this);
    QFont f("Arial", 20, QFont::Bold);
    lblCliente->setFont(f);
    lblCliente->setMaximumHeight(30);

    mainLayout = new QVBoxLayout(this);
    inputLayout = new QHBoxLayout();
    frameLayout = new QVBoxLayout();
    idLayout = new QHBoxLayout();
    nomeLayout = new QHBoxLayout();
    cognomeLayout = new QHBoxLayout();
    creditoLayout = new QHBoxLayout();
    puntiLayout = new QHBoxLayout();
    lvlLayout = new QHBoxLayout();
    btnLayout = new QVBoxLayout();
    btn2Layout = new QVBoxLayout();

    lblId = new QLabel("Id:",frmCliente);
    lblNome = new QLabel("Nome:",frmCliente);
    lblCognome = new QLabel("Cognome:",frmCliente);
    lblCredito = new QLabel("Credito:",frmCliente);
    lblPunti = new QLabel("Punti:",frmCliente);
    lblLivello = new QLabel("Livello:",frmCliente);
    lblLivelloEff = new QLabel("0",frmCliente);

    cmbId = new QComboBox(frmCliente);
    cmbId->setFixedWidth(95);
    lneNome = new QLineEdit(frmCliente);
    lneNome->setDisabled(true);
    lneNome->setFixedWidth(95);
    lneCognome = new QLineEdit(frmCliente);
    lneCognome->setDisabled(true);
    lneCognome->setFixedWidth(95);
    lblCreditoEff = new QLabel("0",frmCliente);
    lblPuntiEff = new QLabel("0",frmCliente);
    prgLivello = new QProgressBar(frmCliente);

    btnCrea = new QPushButton("Crea utente",this);
    btnElimina = new QPushButton("Elimina Utente",this);
    btnUpgrade = new QPushButton("Upgrade Utente",this);
    btnLevelUp = new QPushButton("Level Up",this);
    btnConverti = new QPushButton("Converti punti a credito",this);
    lblDeposita = new QLabel("Credito da ricaricare:",this);
    lneDeposita = new QLineEdit(this);
    btnDeposita = new QPushButton("Deposita",this);

    idLayout->addWidget(lblId);
    idLayout->addWidget(cmbId);
    idLayout->setDirection(QBoxLayout::LeftToRight);

    nomeLayout->addWidget(lblNome);
    nomeLayout->addWidget(lneNome);
    nomeLayout->setDirection(QBoxLayout::LeftToRight);

    cognomeLayout->addWidget(lblCognome);
    cognomeLayout->addWidget(lneCognome);
    cognomeLayout->setDirection(QBoxLayout::LeftToRight);

    creditoLayout->addWidget(lblCredito);
    creditoLayout->addWidget(lblCreditoEff);
    creditoLayout->setDirection(QBoxLayout::LeftToRight);
    creditoLayout->setContentsMargins(0,0,40,0);

    puntiLayout->addWidget(lblPunti);
    puntiLayout->addWidget(lblPuntiEff);
    puntiLayout->setDirection(QBoxLayout::LeftToRight);
    puntiLayout->setContentsMargins(0,0,40,0);

    lvlLayout->addWidget(lblLivello);
    lvlLayout->addWidget(lblLivelloEff);
    lvlLayout->addWidget(prgLivello);
    lvlLayout->setDirection(QBoxLayout::LeftToRight);

    btnLayout->addWidget(btnCrea);
    btnLayout->addWidget(btnElimina);
    btnLayout->addWidget(btnUpgrade);
    btnLayout->addWidget(btnLevelUp);
    btnLayout->addWidget(btnConverti);
    btn2Layout->addWidget(lblDeposita);
    btn2Layout->addWidget(lneDeposita);
    btn2Layout->addWidget(btnDeposita);
    btnLayout->setAlignment(Qt::AlignCenter);
    btn2Layout->setContentsMargins(0,25,0,90);

    frmCliente->setLayout(frameLayout);
    frameLayout->addLayout(idLayout);
    frameLayout->addLayout(nomeLayout);
    frameLayout->addLayout(cognomeLayout);
    frameLayout->addLayout(creditoLayout);
    frameLayout->addLayout(puntiLayout);
    frameLayout->addLayout(lvlLayout);
    frameLayout->setAlignment(Qt::AlignCenter);

    inputLayout->addWidget(frmCliente);
    inputLayout->addLayout(btnLayout);
    inputLayout->addLayout(btn2Layout);

    mainLayout->addWidget(lblCliente);
    mainLayout->addLayout(inputLayout);
}

void ZonaClienteWidget::addCmbId(QString s)const
{
    cmbId->addItem(s);
}

void ZonaClienteWidget::removeCurrentCmbId() const
{
    cmbId->removeItem(cmbId->currentIndex());
}

void ZonaClienteWidget::setCmbEnabled(bool e)
{
    cmbId->setEnabled(e);
}

void ZonaClienteWidget::setCmbText(QString s) const
{
    cmbId->setCurrentText(s);
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

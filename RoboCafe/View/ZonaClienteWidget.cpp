#include "ZonaClienteWidget.h"
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QProgressBar>

ZonaClienteWidget::ZonaClienteWidget(QWidget *parent): QWidget(parent)
{
    QFrame *frmCliente = new QFrame(this);
    //frmCliente->setMaximumSize(400,400);
    QLabel *lblCliente = new QLabel("Cliente:",this);
    lblCliente->setStyleSheet("background-color: rgb(200,150,200)");
    QFont f("Arial", 20, QFont::Bold);
    lblCliente->setFont(f);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    QHBoxLayout *frameLayout = new QHBoxLayout();
    QVBoxLayout *lblLayout = new QVBoxLayout();
    QVBoxLayout *dataLayout = new QVBoxLayout();
    QVBoxLayout *btnLayout = new QVBoxLayout();
    QHBoxLayout *lvlLayout = new QHBoxLayout();

    QLabel *lblNome = new QLabel("Nome:",frmCliente);
    QLabel *lblCognome = new QLabel("Cognome:",frmCliente);
    QLabel *lblCredito = new QLabel("Credito:",frmCliente);
    QLabel *lblPunti = new QLabel("Punti:",frmCliente);
    QLabel *lblLivello = new QLabel("Livello:",frmCliente);
    QLabel *lblLivelloEff = new QLabel("0",frmCliente);

    QComboBox *cmbNome = new QComboBox(frmCliente);
    QLineEdit *lneCognome = new QLineEdit(frmCliente);
    QLineEdit *lneCredito = new QLineEdit(frmCliente);
    QLineEdit *lnePunti = new QLineEdit(frmCliente);
    QProgressBar *prgLivello = new QProgressBar(frmCliente);

    QPushButton *btnUpgrade = new QPushButton("Upgrade Utente",this);
    QPushButton *btnLevelUp = new QPushButton("Level Up",this);
    QPushButton *btnConverti = new QPushButton("Converti punti a credito",this);

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

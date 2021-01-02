#include "CreaUtenteWidget.h"

QPushButton *CreaUtenteWidget::getBtnOk() const
{
    return btnOk;
}

QString CreaUtenteWidget::getLneNome() const
{
    return lneNome->text();
}

QString CreaUtenteWidget::getLneCognome() const
{
    return lneCognome->text();
}

CreaUtenteWidget::tipoUtente CreaUtenteWidget::getTipoSelezionato() const
{
    if(rdoStandard->isChecked())
        return standard;
    if(rdoPlus->isChecked())
        return plus;
    else
        return dipendente;
}

CreaUtenteWidget::~CreaUtenteWidget()
{     
    delete lblNome;
    delete lblCognome;
    delete lneNome;
    delete lneCognome;
    delete btnOk;
    delete rdoStandard;
    delete rdoPlus;
    delete rdoDip;
    delete rdoLayout;
    delete creaLayout;
}

CreaUtenteWidget::CreaUtenteWidget(QDialog *parent):QDialog(parent)
{
    creaLayout= new QVBoxLayout(this);
    rdoLayout = new QHBoxLayout();

    lblNome = new QLabel("Nome:",this);
    lblCognome = new QLabel("Cognome:",this);
    lneNome = new QLineEdit(this);
    lneCognome = new QLineEdit(this);
    btnOk = new QPushButton("Ok",this);
    rdoStandard = new QRadioButton("Standard",this);
    rdoStandard->setChecked(true);
    rdoPlus = new QRadioButton("Plus",this);
    rdoDip = new QRadioButton("Dipendente",this);

    rdoLayout->addWidget(rdoStandard);
    rdoLayout->addWidget(rdoPlus);
    rdoLayout->addWidget(rdoDip);

    setLayout(creaLayout);
    creaLayout->addWidget(lblNome);
    creaLayout->addWidget(lneNome);
    creaLayout->addWidget(lblCognome);
    creaLayout->addWidget(lneCognome);
    creaLayout->addLayout(rdoLayout);
    creaLayout->addWidget(btnOk);
    show();
}

void CreaUtenteWidget::reject()
{
    emit sigEnableView();
    QDialog::reject();
}

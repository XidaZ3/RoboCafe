#include "ErroreWidget.h"
#include <iostream>
QPushButton *ErroreWidget::getOkConferma() const
{
    return okConferma;
}

void ErroreWidget::reject()
{
    emit sigEnableView();
    QDialog::reject();
}

ErroreWidget::~ErroreWidget()
{

    delete lblMessaggio;
    delete okConferma;
    delete diaLayout;
}

ErroreWidget::ErroreWidget(QDialog *parent):QDialog(parent){

    diaLayout = new QVBoxLayout(this);
    lblMessaggio = new QLabel("Errore:",this);
    okConferma = new QPushButton("Ok",this);

    setLayout(diaLayout);
    diaLayout->addWidget(lblMessaggio);
    diaLayout->addWidget(okConferma);
    show();
}

void ErroreWidget::setLblMessaggio(QString s)
{
    lblMessaggio->setText(s);
}

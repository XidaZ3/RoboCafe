#include "ErroreWidget.h"

ErroreWidget::ErroreWidget(QWidget *parent):QWidget(parent){

    mainLayout = new QVBoxLayout(this);
    lblMessaggio = new QLabel("Errore:",this);
    okConferma = new QPushButton("Ok",this);

    mainLayout->addWidget(lblMessaggio);
    mainLayout->addWidget(okConferma);
}

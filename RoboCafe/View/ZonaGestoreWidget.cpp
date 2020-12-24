#include "ZonaGestoreWidget.h"

ZonaGestoreWidget::ZonaGestoreWidget(QWidget *parent): QWidget(parent)
{
    mainLayout = new QHBoxLayout(this);
    portafoglioLayout = new QVBoxLayout();
    refillLayout = new QVBoxLayout();

    intestazioneLayout = new QHBoxLayout();
    acquaLayout = new QHBoxLayout();
    caffeLayout = new QHBoxLayout();
    latteLayout = new QHBoxLayout();
    pizzeLayout = new QHBoxLayout();
    teLayout = new QHBoxLayout();

    lblZona = new QLabel("Zona gestore:",this);
    QFont f("Arial", 15, QFont::DemiBold);
    lblZona->setFont(f);
    lblRefill = new QLabel("Refill:",this);
    lblQuantita = new QLabel("Quantità:",this);
    lblPortafoglio = new QLabel("Portafoglio:",this);

    lblPortafoglioDati = new QLabel("123:",this);
    lblPreleva = new QLabel("Quantità:",this);
    lneCredito = new QLineEdit(this);
    btnPreleva = new QPushButton("Preleva portafoglio",this);

    lblAcqua = new QLabel("123:",this);
    lblAcqua->setMinimumWidth(76);
    lblCaffe = new QLabel("456:",this);
    lblLatte = new QLabel("789:",this);
    lblTe = new QLabel("123:",this);
    lblPizze = new QLabel("456:",this);

    btnAcqua= new QPushButton("Acqua",this);
    btnCaffe = new QPushButton("Caffe",this);
    btnLatte = new QPushButton("Latte",this);
    btnTe = new QPushButton("Te",this);
    btnPizze = new QPushButton("Pizze",this);

    portafoglioLayout->addWidget(lblZona);
    portafoglioLayout->addWidget(lblPortafoglio);
    portafoglioLayout->addWidget(lblPortafoglioDati);
    portafoglioLayout->addWidget(lblPreleva);
    portafoglioLayout->addWidget(lneCredito);
    portafoglioLayout->addWidget(btnPreleva);

    intestazioneLayout->addWidget(lblQuantita);
    intestazioneLayout->addWidget(lblRefill);

    acquaLayout->addWidget(lblAcqua);
    acquaLayout->addWidget(btnAcqua);

    caffeLayout->addWidget(lblCaffe);
    caffeLayout->addWidget(btnCaffe);

    latteLayout->addWidget(lblLatte);
    latteLayout->addWidget(btnLatte);

    pizzeLayout->addWidget(lblPizze);
    pizzeLayout->addWidget(btnPizze);

    teLayout->addWidget(lblTe);
    teLayout->addWidget(btnTe);

    refillLayout->addLayout(intestazioneLayout);
    refillLayout->addLayout(acquaLayout);
    refillLayout->addLayout(caffeLayout);
    refillLayout->addLayout(latteLayout);
    refillLayout->addLayout(pizzeLayout);
    refillLayout->addLayout(teLayout);

    mainLayout->addLayout(portafoglioLayout);
    mainLayout->addLayout(refillLayout);

    setStyleSheet("background-color: rgb(200,150,200)");

}

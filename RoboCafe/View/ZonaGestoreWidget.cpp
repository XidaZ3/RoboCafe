#include "ZonaGestoreWidget.h"

QPushButton *ZonaGestoreWidget::getBtnAcqua() const
{
    return btnAcqua;
}

QPushButton *ZonaGestoreWidget::getBtnCaffe() const
{
    return btnCaffe;
}

QPushButton *ZonaGestoreWidget::getBtnLatte() const
{
    return btnLatte;
}

QPushButton *ZonaGestoreWidget::getBtnTe() const
{
    return btnTe;
}

QPushButton *ZonaGestoreWidget::getBtnPizze() const
{
    return btnPizze;
}

QPushButton *ZonaGestoreWidget::getBtnPreleva() const
{
    return btnPreleva;
}

ZonaGestoreWidget::~ZonaGestoreWidget()
{   
    delete lblZona;
    delete lblRefill;
    delete lblQuantita;
    delete lblPortafoglio;

    delete lblPortafoglioDati;
    delete lblPreleva;
    delete lneCredito;
    delete btnPreleva;

    delete lblAcqua;
    delete lblCaffe;
    delete lblLatte;
    delete lblTe;
    delete lblPizze;

    delete btnAcqua;
    delete btnCaffe;
    delete btnLatte;
    delete btnTe;
    delete btnPizze;

    delete intestazioneLayout;
    delete acquaLayout;
    delete caffeLayout;
    delete latteLayout;
    delete pizzeLayout;
    delete teLayout;
    delete portafoglioLayout;
    delete refillLayout;
    delete mainLayout;
}

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

    lblZona = new QLabel("Zona gestore",this);
    QFont f("Arial", 15, QFont::DemiBold);
    lblZona->setFont(f);
    lblRefill = new QLabel("Refill:",this);
    lblQuantita = new QLabel("Quantità:",this);
    lblPortafoglio = new QLabel("Portafoglio:",this);

    lblPortafoglioDati = new QLabel("100",this);
    lblPreleva = new QLabel("Quantità:",this);
    lneCredito = new QLineEdit(this);
    btnPreleva = new QPushButton("Preleva portafoglio",this);

    lblAcqua = new QLabel("5",this);
    lblAcqua->setMinimumWidth(76);
    lblCaffe = new QLabel("20",this);
    lblLatte = new QLabel("2",this);
    lblTe = new QLabel("20",this);
    lblPizze = new QLabel("20",this);

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
}

void ZonaGestoreWidget::setLblAcqua(QString s) const
{
    lblAcqua->setText(s);
}

void ZonaGestoreWidget::setLblCaffe(QString s) const
{
    lblCaffe->setText(s);
}

void ZonaGestoreWidget::setLblLatte(QString s) const
{
    lblLatte->setText(s);
}

void ZonaGestoreWidget::setLblTe(QString s) const
{
    lblTe->setText(s);
}

void ZonaGestoreWidget::setLblPizze(QString s) const
{
    lblPizze->setText(s);
}

void ZonaGestoreWidget::setLblPortafoglioDati(QString s) const
{
    lblPortafoglioDati->setText(s);
}

QString ZonaGestoreWidget::getLneCredito() const
{
    return lneCredito->text();
}

void ZonaGestoreWidget::setLneCredito(QString s) const
{
    lneCredito->setText(s);
}


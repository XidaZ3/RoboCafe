#include "ZonaGestoreWidget.h"

#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLineEdit>

ZonaGestoreWidget::ZonaGestoreWidget(QWidget *parent): QWidget(parent)
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QVBoxLayout *portafoglioLayout = new QVBoxLayout();
    QVBoxLayout *refillLayout = new QVBoxLayout();

    QHBoxLayout *intestazioneLayout = new QHBoxLayout();
    QHBoxLayout *acquaLayout = new QHBoxLayout();
    QHBoxLayout *caffeLayout = new QHBoxLayout();
    QHBoxLayout *latteLayout = new QHBoxLayout();
    QHBoxLayout *pizzeLayout = new QHBoxLayout();
    QHBoxLayout *teLayout = new QHBoxLayout();

    QLabel *lblZona = new QLabel("Zona gestore:",this);
    QFont f("Arial", 15, QFont::DemiBold);
    lblZona->setFont(f);
    QLabel *lblRefill = new QLabel("Refill:",this);
    QLabel *lblQuantita = new QLabel("Quantità:",this);
    QLabel *lblPortafoglio = new QLabel("Portafoglio:",this);

    QLabel *lblPortafoglioDati = new QLabel("123:",this);
    QLabel *lblPreleva = new QLabel("Quantità:",this);
    QLineEdit *lneCredito = new QLineEdit(this);
    QPushButton *btnPreleva = new QPushButton("Preleva portafoglio",this);

    QLabel *lblAcqua = new QLabel("123:",this);
     lblAcqua->setMinimumWidth(76);
    QLabel *lblCaffe = new QLabel("456:",this);
    QLabel *lblLatte = new QLabel("789:",this);
    QLabel *lblTe = new QLabel("123:",this);
    QLabel *lblPizze = new QLabel("456:",this);

    QPushButton *btnAcqua= new QPushButton("Acqua",this);
    QPushButton *btnCaffe = new QPushButton("Caffe",this);
    QPushButton *btnLatte = new QPushButton("Latte",this);
    QPushButton *btnTe = new QPushButton("Te",this);
    QPushButton *btnPizze = new QPushButton("Pizze",this);

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

#include "MostraProdottoWidget.h"

void MostraProdottoWidget::addBoolChoiceOne()
{
    boolChoiceOneLayout->addWidget(lblBoolChoiceOne);
    boolChoiceOneLayout->addWidget(rdoBoolChoiceOneTrue);
    boolChoiceOneLayout->addWidget(rdoBoolChoiceOneFalse);
    grbBoolChoiceOne->setLayout(boolChoiceOneLayout);
    grbBoolChoiceOne->hide();
    mainLayout->addWidget(grbBoolChoiceOne);
}

void MostraProdottoWidget::addBoolChoiceTwo()
{
    boolChoiceTwoLayout->addWidget(lblBoolChoiceTwo);
    boolChoiceTwoLayout->addWidget(rdoBoolChoiceTwoTrue);
    boolChoiceTwoLayout->addWidget(rdoBoolChoiceTwoFalse);
    grbBoolChoiceTwo->setLayout(boolChoiceTwoLayout);
    grbBoolChoiceTwo->hide();
    mainLayout->addWidget(grbBoolChoiceTwo);
}

void MostraProdottoWidget::addBoolChoiceThree()
{
    boolChoiceThreeLayout->addWidget(lblBoolChoiceThree);
    boolChoiceThreeLayout->addWidget(rdoBoolChoiceThreeTrue);
    boolChoiceThreeLayout->addWidget(rdoBoolChoiceThreeFalse);
    grbBoolChoiceThree->setLayout(boolChoiceThreeLayout);
    grbBoolChoiceThree->hide();
    mainLayout->addWidget(grbBoolChoiceThree);
}

void MostraProdottoWidget::addIntChoiceOne()
{
    intChoiceOneLayout->addWidget(lblIntChoiceOne);
    intChoiceOneLayout->addWidget(spbIntChoiceOne);
    grbIntChoiceOne->setLayout(intChoiceOneLayout);
    grbIntChoiceOne->hide();
    mainLayout->addWidget(grbIntChoiceOne);
}

MostraProdottoWidget::MostraProdottoWidget(QWidget *parent):QWidget(parent)
{
    prodotto = nullptr;
    mainLayout = new QVBoxLayout(this);
    descrizioneLayout = new QHBoxLayout();
    lblLayout = new QVBoxLayout();
    rdoLayout = new QHBoxLayout();
    boolChoiceOneLayout = new QHBoxLayout();
    boolChoiceTwoLayout = new QHBoxLayout();
    boolChoiceThreeLayout = new QHBoxLayout();
    intChoiceOneLayout = new QHBoxLayout();

    grbBoolChoiceOne = new QGroupBox();
    grbBoolChoiceOne->setMinimumHeight(80);
    grbBoolChoiceTwo = new QGroupBox();
    grbBoolChoiceTwo->setMinimumHeight(80);
    grbBoolChoiceThree = new QGroupBox();
    grbBoolChoiceThree->setMinimumHeight(80);
    grbIntChoiceOne = new QGroupBox();
    grbIntChoiceOne->setMinimumHeight(80);

    lblCosto = new QLabel("Costo base:",this);
    lblCostoDati = new QLabel(this);
    lblCalorie = new QLabel("Calorie:",this);
    lblCalorieDati = new QLabel(this);
    lblCosto->setMaximumHeight(15);
    lblCostoDati->setMaximumHeight(15);
    lblCalorie->setMaximumHeight(15);
    lblCalorieDati->setMaximumHeight(15);

    lblImmagine= new QLabel(this);

    lblDimensione = new QLabel("Dimensione:",this);
    rdoGrande = new QRadioButton("Grande",this);
    rdoMedia = new QRadioButton("Medio",this);
    rdoPiccolo = new QRadioButton("Piccolo",this);

    btnConferma= new QPushButton("Conferma scelta",this);

    lblLayout->addWidget(lblCosto);
    lblLayout->addWidget(lblCostoDati);
    lblLayout->addWidget(lblCalorie);
    lblLayout->addWidget(lblCalorieDati);

    descrizioneLayout->addLayout(lblLayout);
    descrizioneLayout->addWidget(lblImmagine);

    rdoLayout->addWidget(lblDimensione);
    rdoLayout->addWidget(rdoPiccolo);
    rdoLayout->addWidget(rdoMedia);
    rdoLayout->addWidget(rdoGrande);

    //Scelta booleana 1
    lblBoolChoiceOne = new QLabel();
    rdoBoolChoiceOneTrue = new QRadioButton("Si");
    rdoBoolChoiceOneFalse= new QRadioButton("No");

    //Scelta booleana 2
    lblBoolChoiceTwo = new QLabel();
    rdoBoolChoiceTwoTrue= new QRadioButton("Si");
    rdoBoolChoiceTwoFalse= new QRadioButton("No");

    //Scelta booleana 3
    lblBoolChoiceThree = new QLabel();
    rdoBoolChoiceThreeTrue= new QRadioButton("Si");
    rdoBoolChoiceThreeFalse= new QRadioButton("No");


    //Scelta intera 1
    lblIntChoiceOne = new QLabel();
    spbIntChoiceOne = new QSpinBox();

    mainLayout->addLayout(descrizioneLayout);
    mainLayout->addLayout(rdoLayout);

    addIntChoiceOne();
    addBoolChoiceOne();
    addBoolChoiceTwo();
    addBoolChoiceThree();
    mainLayout->addWidget(btnConferma);
    connect(btnConferma,SIGNAL(clicked()),this,SLOT(btnTriggered()));
}


MostraProdottoWidget::~MostraProdottoWidget()
{
    delete prodotto;

    delete lblDimensione;
    delete rdoGrande;
    delete rdoMedia;
    delete rdoPiccolo;
    delete lblBoolChoiceOne;
    delete rdoBoolChoiceOneTrue;
    delete rdoBoolChoiceOneFalse;
    delete lblBoolChoiceTwo;
    delete rdoBoolChoiceTwoTrue;
    delete rdoBoolChoiceTwoFalse;
    delete lblBoolChoiceThree;
    delete rdoBoolChoiceThreeTrue;
    delete rdoBoolChoiceThreeFalse;
    delete lblIntChoiceOne;
    delete spbIntChoiceOne;
    delete btnConferma;


    delete rdoLayout;
    delete boolChoiceOneLayout;
    delete boolChoiceTwoLayout;
    delete boolChoiceThreeLayout;
    delete intChoiceOneLayout;

    delete grbBoolChoiceOne;
    delete grbBoolChoiceTwo;
    delete grbBoolChoiceThree;
    delete grbIntChoiceOne;

    delete lblCosto;
    delete lblCostoDati;
    delete lblCalorie;
    delete lblCalorieDati;
    delete lblImmagine;
    delete lblLayout;
    delete descrizioneLayout;
    delete mainLayout;

}

void MostraProdottoWidget::setProdotto(Prodotto *value)
{
    if(value !=nullptr){
        prodotto = value;
        Te* ptrTe = dynamic_cast<Te*>(prodotto);
        if(ptrTe != nullptr){
            setInterfacciaTe();
        }
        Caffe* ptrCaffe = dynamic_cast<Caffe*>(prodotto);
        if(ptrCaffe != nullptr){
            setInterfacciaCaffe();
        }
        Pizza* ptrPizza = dynamic_cast<Pizza*>(prodotto);
        if(ptrPizza != nullptr){
            setInterfacciaPizza();
        }

        lblCalorieDati->setText(QString::number(prodotto->getCalorie()));
        lblCostoDati->setText(QString::number(prodotto->getPrezzoBase()));

        QPixmap map(QString::fromStdString(prodotto->getPath()));
        lblImmagine->setPixmap(map);
        switch(prodotto->getDimensione()){
            case Dimensione::Piccolo: rdoPiccolo->setChecked(true);break;
            case Dimensione::Medio: rdoMedia->setChecked(true);break;
            case Dimensione::Grande: rdoGrande->setChecked(true);
        }
    }else{
        resetInterfaccia();
    }
}

void MostraProdottoWidget::setInterfacciaPizza()
{
    Pizza* pizza = static_cast<Pizza*>(prodotto);

    mainLayout->removeWidget(btnConferma);
    lblIntChoiceOne->setText("Temperatura:");
    spbIntChoiceOne->setRange(180,200);
    spbIntChoiceOne->setSingleStep(5);

    spbIntChoiceOne->setValue(pizza->getTemperatura());

    lblBoolChoiceOne->setText("Extra topping:");
    rdoBoolChoiceOneTrue->setChecked(pizza->getExtra());

    if(!grbIntChoiceOne->isVisible())grbIntChoiceOne->show();
    if(!grbBoolChoiceOne->isVisible())grbBoolChoiceOne->show();
    grbBoolChoiceTwo->hide();
    grbBoolChoiceThree->hide();

    mainLayout->addWidget(btnConferma);

}

void MostraProdottoWidget::setInterfacciaTe()
{
    Te* te = static_cast<Te*>(prodotto);
    mainLayout->removeWidget(btnConferma);
    lblIntChoiceOne->setText("Filtri:");
    spbIntChoiceOne->setRange(1,3);
    spbIntChoiceOne->setSingleStep(1);
    spbIntChoiceOne->setValue(te->getFiltri());

    lblBoolChoiceOne->setText("Ghiaccio:");
    rdoBoolChoiceOneTrue->setChecked(te->getGhiaccio());
    lblBoolChoiceTwo->setText("Limone:");
    rdoBoolChoiceTwoTrue->setChecked(te->getLimone());

    if(!grbIntChoiceOne->isVisible())grbIntChoiceOne->show();
    if(!grbBoolChoiceOne->isVisible())grbBoolChoiceOne->show();
    if(!grbBoolChoiceTwo->isVisible())grbBoolChoiceTwo->show();
    grbBoolChoiceThree->hide();

    mainLayout->addWidget(btnConferma);

}

void MostraProdottoWidget::setInterfacciaCaffe()
{
    Caffe* caffe = static_cast<Caffe*>(prodotto);
    mainLayout->removeWidget(btnConferma);
    lblIntChoiceOne->setText("Cialde:");
    spbIntChoiceOne->setRange(1,3);
    spbIntChoiceOne->setSingleStep(1);
    spbIntChoiceOne->setValue(caffe->getCialdeCaffe());

    lblBoolChoiceOne->setText("Ghiaccio:");
    if(caffe->getGhiaccio())
        rdoBoolChoiceOneTrue->setChecked(true);
    else
        rdoBoolChoiceOneFalse->setChecked(true);
    lblBoolChoiceTwo->setText("Cacao:");
    if(caffe->getCacao())
        rdoBoolChoiceTwoTrue->setChecked(true);
    else
        rdoBoolChoiceTwoFalse->setChecked(true);
    lblBoolChoiceThree->setText("Caramello:");
    if(caffe->getCaramello())
        rdoBoolChoiceThreeTrue->setChecked(true);
    else
        rdoBoolChoiceThreeFalse->setChecked(true);

    if(!grbIntChoiceOne->isVisible())grbIntChoiceOne->show();
    if(!grbBoolChoiceOne->isVisible())grbBoolChoiceOne->show();
    if(!grbBoolChoiceTwo->isVisible())grbBoolChoiceTwo->show();
    if(!grbBoolChoiceThree->isVisible())grbBoolChoiceThree->show();

    mainLayout->addWidget(btnConferma);
}

void MostraProdottoWidget::resetInterfaccia()
{
    grbIntChoiceOne->hide();
    grbBoolChoiceOne->hide();
    grbBoolChoiceTwo->hide();
    grbBoolChoiceThree->hide();
    lblCostoDati->setText("");
    lblCalorieDati->setText("");
    rdoMedia->setChecked(true);
    lblImmagine->setPixmap(QPixmap());
}

void MostraProdottoWidget::btnConfermaEnabled(bool value)
{
    btnConferma->setEnabled(value);
}

QPushButton *MostraProdottoWidget::getBtnConferma() const
{
    return btnConferma;
}

void MostraProdottoWidget::btnTriggered()
{
    Te* ptrTe = dynamic_cast<Te*>(prodotto);
    if(ptrTe != nullptr){
        ptrTe->setDimensione(rdoGrande->isChecked() ? Dimensione::Grande : (rdoMedia->isChecked() ? Dimensione::Medio : Dimensione::Piccolo));
        ptrTe->setFiltri(spbIntChoiceOne->value());
        ptrTe->setGhiaccio(rdoBoolChoiceOneTrue->isChecked());
        ptrTe->setLimone(rdoBoolChoiceTwoTrue->isChecked());
        emit(conferma(ptrTe));
    }else{
        Caffe* ptrCaffe = dynamic_cast<Caffe*>(prodotto);
        if(ptrCaffe != nullptr){
            ptrCaffe->setDimensione(rdoGrande->isChecked() ? Dimensione::Grande : (rdoMedia->isChecked() ? Dimensione::Medio : Dimensione::Piccolo));
            ptrCaffe->setCialdeCaffe(spbIntChoiceOne->value());
            ptrCaffe->setGhiaccio(rdoBoolChoiceOneTrue->isChecked());
            ptrCaffe->setCacao(rdoBoolChoiceTwoTrue->isChecked());
            ptrCaffe->setCaramello(rdoBoolChoiceThreeTrue->isChecked());
            emit(conferma(ptrCaffe));
        }else{
            Pizza* ptrPizza = dynamic_cast<Pizza*>(prodotto);
            if(ptrPizza != nullptr){
                ptrPizza->setDimensione(rdoGrande->isChecked() ? Dimensione::Grande : (rdoMedia->isChecked() ? Dimensione::Medio : Dimensione::Piccolo));
                ptrPizza->setTemperatura(spbIntChoiceOne->value());
                ptrPizza->setExtra(rdoBoolChoiceOneTrue->isChecked());
                emit(conferma(ptrPizza));
            }
        }

    }
    prodotto = nullptr;

}







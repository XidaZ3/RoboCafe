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
    spbLayout->addWidget(lblIntChoiceOne);
    spbLayout->addWidget(spbIntChoiceOne);
    grbIntChoiceOne->setLayout(spbLayout);
    grbIntChoiceOne->hide();
    mainLayout->addWidget(grbIntChoiceOne);
}

MostraProdottoWidget::MostraProdottoWidget(QWidget *parent):QWidget(parent)
{
    this->setGeometry(240,250,400,200);
    mainLayout = new QVBoxLayout(this);
    descrizioneLayout = new QHBoxLayout();
    lblLayout = new QVBoxLayout();
    rdoLayout = new QHBoxLayout();
    boolChoiceOneLayout = new QHBoxLayout();
    boolChoiceTwoLayout = new QHBoxLayout();
    boolChoiceThreeLayout = new QHBoxLayout();
    spbLayout = new QHBoxLayout();

    grbBoolChoiceOne = new QGroupBox();
    grbBoolChoiceTwo = new QGroupBox();
    grbBoolChoiceThree = new QGroupBox();
    grbIntChoiceOne = new QGroupBox();

    lblProdotto = new QLabel("Prodotto selezionato:",this);
    lblProdotto->setStyleSheet("background-color: rgb(200,150,200)");
    QFont f("Arial", 15, QFont::DemiBold);
    lblProdotto->setFont(f);

    lblCosto = new QLabel("Costo base:",this);
    lblCostoDati = new QLabel();
    lblCalorie = new QLabel("Calorie:",this);
    lblCalorieDati = new QLabel();
    lblCosto->setMaximumHeight(15);
    lblCostoDati->setMaximumHeight(15);
    lblCalorie->setMaximumHeight(15);
    lblCalorieDati->setMaximumHeight(15);

    frmImmagine= new QFrame(this);

    lblQuantita = new QLabel("Dimensione:",this);
    rdoGrande = new QRadioButton("Grande",this);
    rdoMedia = new QRadioButton("Medio",this);
    rdoPiccolo = new QRadioButton("Piccolo",this);

    btnConferma= new QPushButton("Conferma scelta",this);

    lblLayout->addWidget(lblCosto);
    lblLayout->addWidget(lblCostoDati);
    lblLayout->addWidget(lblCalorie);
    lblLayout->addWidget(lblCalorieDati);

    descrizioneLayout->addLayout(lblLayout);
    descrizioneLayout->addWidget(frmImmagine);

    rdoLayout->addWidget(lblQuantita);
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

    mainLayout->addWidget(lblProdotto);
    mainLayout->addLayout(descrizioneLayout);
    mainLayout->addLayout(rdoLayout);

    addIntChoiceOne();
    addBoolChoiceOne();
    addBoolChoiceTwo();
    addBoolChoiceThree();



    mainLayout->addWidget(btnConferma);

    connect(btnConferma,SIGNAL(clicked()),this,SLOT(btnTriggered()));

    setStyleSheet("background-color: rgb(200,150,200)");
}

void MostraProdottoWidget::setProdotto(Prodotto *value)
{
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
    lblCostoDati->setText(QString::number(prodotto->getPrezzo_base()));

    switch(prodotto->getDimensione()){
        case Dimensione::Piccolo: rdoPiccolo->setChecked(true);break;
        case Dimensione::Medio: rdoMedia->setChecked(true);break;
        case Dimensione::Grande: rdoGrande->setChecked(true);
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
    rdoBoolChoiceOneFalse->setChecked(pizza->getExtra());

    if(!grbIntChoiceOne->isVisible())grbIntChoiceOne->show();
    if(!grbBoolChoiceOne->isVisible())grbBoolChoiceOne->show();
    grbBoolChoiceTwo->hide();
    grbBoolChoiceThree->hide();

    mainLayout->addWidget(btnConferma);
    this->setGeometry(240,250,400,270);

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
    rdoBoolChoiceOneFalse->setChecked(te->getGhiaccio());
    lblBoolChoiceTwo->setText("Limone:");
    rdoBoolChoiceTwoFalse->setChecked(te->getLimone());

    if(!grbIntChoiceOne->isVisible())grbIntChoiceOne->show();
    if(!grbBoolChoiceOne->isVisible())grbBoolChoiceOne->show();
    if(!grbBoolChoiceTwo->isVisible())grbBoolChoiceTwo->show();
    grbBoolChoiceThree->hide();

    mainLayout->addWidget(btnConferma);
    this->setGeometry(240,250,400,320);

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
    rdoBoolChoiceOneFalse->setChecked(caffe->getGhiaccio());
    lblBoolChoiceTwo->setText("Cacao:");
    rdoBoolChoiceTwoFalse->setChecked(caffe->getCacao());
    lblBoolChoiceThree->setText("Caramello:");
    rdoBoolChoiceThreeFalse->setChecked(caffe->getCaramello());

    if(!grbIntChoiceOne->isVisible())grbIntChoiceOne->show();
    if(!grbBoolChoiceOne->isVisible())grbBoolChoiceOne->show();
    if(!grbBoolChoiceTwo->isVisible())grbBoolChoiceTwo->show();
    if(!grbBoolChoiceThree->isVisible())grbBoolChoiceThree->show();

    mainLayout->addWidget(btnConferma);
    this->setGeometry(240,250,400,370);
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
    this->setGeometry(400,0,400,200);
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
    }
    Caffe* ptrCaffe = dynamic_cast<Caffe*>(prodotto);
    if(ptrCaffe != nullptr){
        ptrCaffe->setDimensione(rdoGrande->isChecked() ? Dimensione::Grande : (rdoMedia->isChecked() ? Dimensione::Medio : Dimensione::Piccolo));
        ptrCaffe->setCialdeCaffe(spbIntChoiceOne->value());
        ptrCaffe->setGhiaccio(rdoBoolChoiceOneTrue->isChecked());
        ptrCaffe->setCacao(rdoBoolChoiceTwoTrue->isChecked());
        ptrCaffe->setCaramello(rdoBoolChoiceThreeTrue->isChecked());
        emit(conferma(ptrCaffe));
    }
    Pizza* ptrPizza = dynamic_cast<Pizza*>(prodotto);
    if(ptrPizza != nullptr){
        ptrPizza->setDimensione(rdoGrande->isChecked() ? Dimensione::Grande : (rdoMedia->isChecked() ? Dimensione::Medio : Dimensione::Piccolo));
        ptrPizza->setTemperatura(spbIntChoiceOne->value());
        ptrPizza->setExtra(rdoBoolChoiceOneTrue->isChecked());
        emit(conferma(ptrPizza));
    }
}







#ifndef MOSTRAPRODOTTOWIDGET_H
#define MOSTRAPRODOTTOWIDGET_H
#include <QWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class MostraProdottoWidget:public QWidget
{
    Q_OBJECT
private:
    // Pizza: Dimensione, temperatura, extra
    // Te: Dimensione, Acqua, ghiaccio (bool), latte (float), filtri (int), limone (bool)
    // Caffe: Dimension, Acqua, ghiaccio (bool), latte (float), cialde (int), cacao  (bool), caramello  (bool)
    QVBoxLayout *mainLayout;
    QHBoxLayout *descrizioneLayout;
    QVBoxLayout *lblLayout;
    QHBoxLayout *rdoLayout;

    QLabel *lblProdotto;
    QLabel *lblCosto;
    QLabel *lblCostoDati;
    QLabel *lblCalorie;
    QLabel *lblCalorieDati;

    QFrame *frmImmagine;

    QLabel *lblQuantita;
    QRadioButton *rdoGrande;
    QRadioButton *rdoMedia;
    QRadioButton *rdoPiccolo;

    QPushButton *btnConferma;
public:
    MostraProdottoWidget(QWidget *parent=nullptr);
signals:
};

#endif // MOSTRAPRODOTTOWIDGET_H

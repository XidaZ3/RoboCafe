#ifndef ZONAGESTOREWIDGET_H
#define ZONAGESTOREWIDGET_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLineEdit>

class ZonaGestoreWidget:public QWidget
{
private:
    QHBoxLayout *mainLayout;
    QVBoxLayout *portafoglioLayout;
    QVBoxLayout *refillLayout;

    QHBoxLayout *intestazioneLayout;
    QHBoxLayout *acquaLayout;
    QHBoxLayout *caffeLayout;
    QHBoxLayout *latteLayout;
    QHBoxLayout *pizzeLayout;
    QHBoxLayout *teLayout;

    QLabel *lblZona;
    QLabel *lblRefill;
    QLabel *lblQuantita;
    QLabel *lblPortafoglio;

    QLabel *lblPortafoglioDati;
    QLabel *lblPreleva;
    QLineEdit *lneCredito;
    QPushButton *btnPreleva;

    QLabel *lblAcqua;
    QLabel *lblCaffe;
    QLabel *lblLatte;
    QLabel *lblTe;
    QLabel *lblPizze;

    QPushButton *btnAcqua;
    QPushButton *btnCaffe;
    QPushButton *btnLatte;
    QPushButton *btnTe;
    QPushButton *btnPizze;
    Q_OBJECT
public:
    ZonaGestoreWidget(QWidget *parent=nullptr);
signals:
};

#endif // ZONAGESTOREWIDGET_H

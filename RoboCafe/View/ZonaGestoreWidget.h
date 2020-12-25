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
    Q_OBJECT
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
public:
    ZonaGestoreWidget(QWidget *parent=nullptr);
    void setLblAcqua(QString s) const;
    void setLblCaffe(QString s) const;
    void setLblLatte(QString s) const;
    void setLblTe(QString s) const;
    void setLblPizze(QString s) const;
    void setLblPortafoglioDati(QString s)const;

    QString getLneCredito() const;
    QPushButton *getBtnAcqua() const;
    QPushButton *getBtnCaffe() const;
    QPushButton *getBtnLatte() const;
    QPushButton *getBtnTe() const;
    QPushButton *getBtnPizze() const;
    QPushButton *getBtnPreleva() const;
};

#endif // ZONAGESTOREWIDGET_H

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
    void setlblAcqua(QString s) const;
    void setlblCaffe(QString s) const;
    void setlblLatte(QString s) const;
    void setlblTe(QString s) const;
    void setlblPizze(QString s) const;
    QPushButton *getBtnAcqua() const;

    QPushButton *getBtnCaffe() const;

    QPushButton *getBtnLatte() const;

    QPushButton *getBtnTe() const;

    QPushButton *getBtnPizze() const;

signals:
};

#endif // ZONAGESTOREWIDGET_H

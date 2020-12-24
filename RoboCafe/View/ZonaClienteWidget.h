#ifndef ZONACLIENTEWIDGET_H
#define ZONACLIENTEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>
#include <QLineEdit>
#include <QComboBox>
#include <QProgressBar>

class ZonaClienteWidget:public QWidget
{
     Q_OBJECT
private:
    QFrame *frmCliente;
    QLabel *lblCliente;

    QVBoxLayout *mainLayout;

    QHBoxLayout *inputLayout;
    QHBoxLayout *frameLayout;
    QVBoxLayout *lblLayout;
    QVBoxLayout *dataLayout;
    QVBoxLayout *btnLayout;
    QHBoxLayout *lvlLayout;

    QLabel *lblNome;
    QLabel *lblCognome;
    QLabel *lblCredito;
    QLabel *lblPunti;
    QLabel *lblLivello;
    QLabel *lblLivelloEff;

    QComboBox *cmbNome;
    QLineEdit *lneCognome;
    QLineEdit *lneCredito;
    QLineEdit *lnePunti;
    QProgressBar *prgLivello;

    QPushButton *btnUpgrade;
    QPushButton *btnLevelUp;
    QPushButton *btnConverti;
public:
    explicit ZonaClienteWidget(QWidget *parent =nullptr);
//    ZonaClienteWidget();
    void setCmbNome(QString s);
    void setLneCognome(QString s);
    void setLneCredito(QString s);
    void setLnePunti(QString s);
    void setLblLivelloEff(QString s);
    void setQProgressBar();

signals:
};

#endif // ZONACLIENTEWIDGET_H

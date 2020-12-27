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

    QLabel *lblId;
    QLabel *lblNome;
    QLabel *lblCognome;
    QLabel *lblCredito;
    QLabel *lblPunti;
    QLabel *lblLivello;
    QLabel *lblLivelloEff;

    QComboBox *cmbId;
    QLineEdit *lneNome;
    QLineEdit *lneCognome;
    QLabel *lblCreditoEff;
    QLabel *lblPuntiEff;
    QProgressBar *prgLivello;

    QPushButton *btnUpgrade;
    QPushButton *btnLevelUp;
    QPushButton *btnConverti;
    QLabel *lblDeposita;
    QLineEdit *lneDeposita;
    QPushButton *btnDeposita;
public:
    explicit ZonaClienteWidget(QWidget *parent =nullptr);
    void addCmbId(QString s)const;

    void setLneNome(QString s)const;
    void setLneCognome(QString s)const;
    void setLblCreditoEff(QString s)const;
    void setLblPuntiEff(QString s)const;
    void setLblLivelloEff(QString s)const;
    void setPrgLivello(int punti)const;
    void setLneDepositaText(QString s)const;
    QString getLneDepositaText() const;
    QString getCmbText()const;
    QPushButton *getBtnUpgrade() const;

    QPushButton *getBtnLevelUp() const;

    QPushButton *getBtnConverti() const;

    QPushButton *getBtnDeposita() const;
    QComboBox *getCmbId() const;
};

#endif // ZONACLIENTEWIDGET_H

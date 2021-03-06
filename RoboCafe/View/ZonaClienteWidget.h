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
    QVBoxLayout *frameLayout;
    QHBoxLayout *idLayout;
    QHBoxLayout *nomeLayout;
    QHBoxLayout *cognomeLayout;
    QHBoxLayout *creditoLayout;
    QHBoxLayout *puntiLayout;
    QHBoxLayout *lvlLayout;
    QVBoxLayout *btnLayout;
    QVBoxLayout *btn2Layout;

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

    QPushButton *btnCrea;
    QPushButton *btnUpgrade;
    QPushButton *btnLevelUp;
    QPushButton *btnConverti;
    QLabel *lblDeposita;
    QLineEdit *lneDeposita;
    QPushButton *btnDeposita;
    QPushButton *btnElimina;
public:
    ~ZonaClienteWidget();
    explicit ZonaClienteWidget(QWidget *parent =nullptr);

    void addCmbId(QString s)const;
    void removeCurrentCmbId()const;

    void setCmbEnabled(bool e);
    void setCmbText(QString s) const;
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
    QPushButton *getBtnCrea() const;
    void setBtnCrea(QPushButton *value);
    QPushButton *getBtnElimina() const;
};

#endif // ZONACLIENTEWIDGET_H

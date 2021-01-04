#ifndef CREAUTENTEWIDGET_H
#define CREAUTENTEWIDGET_H

#include <QWidget>
#include<QLabel>
#include<QLineEdit>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDialog>
#include <QRadioButton>

class CreaUtenteWidget:public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *creaLayout;
    QHBoxLayout *rdoLayout;
    QLabel *lblNome;
    QLabel *lblCognome;
    QLineEdit *lneNome;
    QLineEdit *lneCognome;
    QPushButton *btnOk;
    QRadioButton *rdoStandard;
    QRadioButton *rdoPlus;
    QRadioButton *rdoDip;
    void reject() override;
public:
    enum tipoUtente{
        standard=1,plus=2,dipendente=3
    };
    ~CreaUtenteWidget();
    explicit CreaUtenteWidget(QDialog *parent=nullptr);

    QPushButton *getBtnOk() const;
    QString getLneNome() const;
    QString getLneCognome() const;
    tipoUtente getTipoSelezionato() const;
signals:
    void sigEnableView();
};

#endif // CREAUTENTEWIDGET_H

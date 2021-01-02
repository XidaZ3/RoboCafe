#ifndef ERROREWIDGET_H
#define ERROREWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDialog>

class ErroreWidget:public QDialog
{
    Q_OBJECT
private:
    QVBoxLayout *diaLayout;
    QLabel *lblMessaggio;
    QPushButton *okConferma;
    void reject() override;
public:
    ~ErroreWidget();
    explicit ErroreWidget(QDialog *parent = nullptr);
    void setLblMessaggio(QString s);
    QPushButton *getOkConferma() const;
signals:
    void sigEnableView();
};

#endif // ERROREWIDGET_H

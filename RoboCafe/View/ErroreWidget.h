#ifndef ERROREWIDGET_H
#define ERROREWIDGET_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class ErroreWidget:public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout *mainLayout;
    QLabel *lblMessaggio;
    QPushButton *okConferma;
public:
    explicit ErroreWidget(QWidget *parent = nullptr);
};

#endif // ERROREWIDGET_H

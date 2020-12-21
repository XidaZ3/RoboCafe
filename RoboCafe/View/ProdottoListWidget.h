#ifndef PRODOTTOLISTWIDGET_H
#define PRODOTTOLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "Model/Vettore.h"
#include "ProdottoItemWidget.h"

class ProdottoListWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* vLayout;
    Vettore<ProdottoItemWidget> vettoreProdotti;
public:
    explicit ProdottoListWidget(const Vettore<ProdottoItemWidget>& prodotti, QWidget *parent = nullptr);

signals:

};

#endif // PRODOTTOLISTWIDGET_H

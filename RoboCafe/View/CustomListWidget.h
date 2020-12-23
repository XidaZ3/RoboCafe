#ifndef PRODOTTOLISTWIDGET_H
#define PRODOTTOLISTWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include "Model/Vettore.h"
#include "ProdottoItemWidget.h"
#include "DettaglioProdottoItemWidget.h"
#include "ScontrinoItemWidget.h"

class CustomListWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* vLayout;
    Vettore<ProdottoItemWidget*> vettoreProdotti;
    Vettore<DettaglioProdottoItemWidget*> vettoreDettaglioProdotti;
    Vettore<ScontrinoItemWidget*> vettoreScontrino;
public:
    explicit CustomListWidget(const Vettore<ProdottoItemWidget*>& prodotti, QWidget *parent = nullptr);
    explicit CustomListWidget(const Vettore<DettaglioProdottoItemWidget*>& prodotti, QWidget *parent = nullptr);
    explicit CustomListWidget(const Vettore<ScontrinoItemWidget*>& prodotti, QWidget *parent = nullptr);

signals:

};

#endif // PRODOTTOLISTWIDGET_H

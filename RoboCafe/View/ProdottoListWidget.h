#ifndef PRODOTTOLISTWIDGET_H
#define PRODOTTOLISTWIDGET_H

#include "ProdottoItemWidget.h"

#include <QWidget>
#include <QVBoxLayout>
#include <vector>

class ProdottoListWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    std::vector<ProdottoItemWidget*> vettoreProdotti;

    void aggiungiWidget();
    void pulisciLayout();
public:
    explicit ProdottoListWidget(QWidget *parent = nullptr);
    ~ProdottoListWidget();
    ProdottoListWidget(const ProdottoListWidget& other);
    ProdottoListWidget& operator= (const ProdottoListWidget& other);
    void addItem(ProdottoItemWidget& value);
    ProdottoItemWidget& getItem(int index);

};

#endif // PRODOTTOLISTWIDGET_H

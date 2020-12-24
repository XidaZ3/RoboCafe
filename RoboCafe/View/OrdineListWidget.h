#ifndef ORDINELISTWIDGET_H
#define ORDINELISTWIDGET_H

#include "OrdineItemWidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <vector>

class OrdineListWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    std::vector<OrdineItemWidget*> vettoreOrdini;

    void aggiungiWidget();
    void pulisciLayout();
public:
    explicit OrdineListWidget(QWidget *parent = nullptr);
    ~OrdineListWidget();
    OrdineListWidget(const OrdineListWidget& other);
    OrdineListWidget& operator= (const OrdineListWidget& other);
    void addItem(OrdineItemWidget& value);
    OrdineItemWidget& getItem(int index);

};

#endif // ORDINELISTWIDGET_H

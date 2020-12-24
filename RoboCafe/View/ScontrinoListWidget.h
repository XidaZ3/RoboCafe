#ifndef SCONTRINOLISTWIDGET_H
#define SCONTRINOLISTWIDGET_H

#include "ScontrinoItemWidget.h"
#include <QWidget>
#include <QVBoxLayout>
#include <vector>

class ScontrinoListWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    std::vector<ScontrinoItemWidget*> vettoreScontrino;

    void aggiungiWidget();
    void pulisciLayout();
public:
    explicit ScontrinoListWidget(QWidget *parent = nullptr);
    ~ScontrinoListWidget();
    ScontrinoListWidget(const ScontrinoListWidget& other);
    ScontrinoListWidget& operator= (const ScontrinoListWidget& other);
    void addItem(ScontrinoItemWidget& value);
    ScontrinoItemWidget& getItem(int index);

};

#endif // SCONTRINOLISTWIDGET_H

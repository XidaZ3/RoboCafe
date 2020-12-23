#ifndef SCONTRINOITEMWIDGET_H
#define SCONTRINOITEMWIDGET_H

#include <QWidget>
#include "Model/Prodotto.h"
#include "Model/Vettore.h"

class ScontrinoItemWidget : public QWidget
{
    Q_OBJECT
private:
    Prodotto* prodotto;
public:
    explicit ScontrinoItemWidget(Prodotto* prodotto,QWidget *parent = nullptr);
    ~ScontrinoItemWidget();
    ScontrinoItemWidget();
    ScontrinoItemWidget(const ScontrinoItemWidget& other);
    ScontrinoItemWidget operator=(const ScontrinoItemWidget& other);
    Prodotto *getProdotto() const;
    void setProdotto(Prodotto *value);
    Vettore<std::string> getDettagli (Prodotto* prodotto) const;

signals:

};

#endif // SCONTRINOITEMWIDGET_H

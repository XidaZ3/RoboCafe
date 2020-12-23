#ifndef PRODOTTOITEMWIDGET_H
#define PRODOTTOITEMWIDGET_H

#include <QWidget>
#include "Model/Prodotto.h"

class ProdottoItemWidget : public QWidget
{
    Q_OBJECT
    private:
        Prodotto* prodotto;
    public:
        ProdottoItemWidget(Prodotto* prodotto,QWidget *parent = nullptr);
        ProdottoItemWidget();
        ~ProdottoItemWidget();
        ProdottoItemWidget(const ProdottoItemWidget& other);
        ProdottoItemWidget& operator=(const ProdottoItemWidget& other);
        Prodotto *getProdotto() const;
        void setProdotto(Prodotto *value);
};

#endif // PRODOTTOITEMWIDGET_H

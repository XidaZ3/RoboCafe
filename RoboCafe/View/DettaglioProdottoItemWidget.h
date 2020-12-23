#ifndef DETTAGLIOPRODOTTOITEMWIDGET_H
#define DETTAGLIOPRODOTTOITEMWIDGET_H

#include <QWidget>
#include "Model/Prodotto.h"
#include "Model/Vettore.h"

class DettaglioProdottoItemWidget : public QWidget
{
    Q_OBJECT
    private:
        Prodotto* prodotto;
    public:
        DettaglioProdottoItemWidget(Prodotto* prodotto,QWidget *parent = nullptr);
        ~DettaglioProdottoItemWidget();
        DettaglioProdottoItemWidget();
        DettaglioProdottoItemWidget(const DettaglioProdottoItemWidget& other);
        DettaglioProdottoItemWidget& operator=(const DettaglioProdottoItemWidget& other);
        Prodotto *getProdotto() const;
        void setProdotto(Prodotto *value);
        Vettore<std::string> getDettagli (Prodotto* prodotto) const;

signals:

};

#endif // DETTAGLIOPRODOTTOITEMWIDGET_H

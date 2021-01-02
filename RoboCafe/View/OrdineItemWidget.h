#ifndef DETTAGLIOPRODOTTOITEMWIDGET_H
#define DETTAGLIOPRODOTTOITEMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "Model/Vettore.h"

class OrdineItemWidget : public QWidget
{
    Q_OBJECT
private:
    //Layout per la disposizione degli elementi
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QVBoxLayout* bottomLayout;

    //Pulsante per eliminare il prodotto dall'ordine
    QPushButton* btnSubtract;
    //Label per mostrare il nome del prodotto
    QLabel* lblNomeProdotto;
    //Vettore di label per i dettagli del prodotto
    Vettore<QLabel*> vtrDettagli;
    //Indice del widget all'interno del contenitore CustomListWidget
    int index;

    void pulisciBottomLayout();

public:
    OrdineItemWidget(QWidget *parent = nullptr);
    ~OrdineItemWidget();
    OrdineItemWidget(const OrdineItemWidget& other);
    OrdineItemWidget& operator=(const OrdineItemWidget& other);

    void setNomeProdotto(QString nome);
    void setNomeBottone(QString nome);
    void setDettagliProdotto(Vettore<std::string> dettagli);
    QPushButton& getBottone()const;
    int getIndex() const;
    void setIndex(int value);

private slots:
    void buttonTriggered();

signals:
    void btnClicked(int index);

};

#endif // DETTAGLIOPRODOTTOITEMWIDGET_H

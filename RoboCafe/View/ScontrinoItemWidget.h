#ifndef SCONTRINOITEMWIDGET_H
#define SCONTRINOITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <vector>

class ScontrinoItemWidget : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QHBoxLayout* topLayout;
    QVBoxLayout* bottomLayout;
    std::vector<QLabel*> vtrDettagli;
    QLabel* lblPrezzo;
    QLabel* lblNomeProdotto;
    int index;

    void pulisciBottomLayout();
public:
    explicit ScontrinoItemWidget(QWidget *parent = nullptr);
    ~ScontrinoItemWidget();
    ScontrinoItemWidget(const ScontrinoItemWidget& other);
    ScontrinoItemWidget operator=(const ScontrinoItemWidget& other);
    void setNomeProdotto(QString nome);
    void setPrezzoProdotto(QString prezzo);
    void setDettagliProdotto(QStringList dettagli);

    void setIndex(int value);

signals:

};

#endif // SCONTRINOITEMWIDGET_H

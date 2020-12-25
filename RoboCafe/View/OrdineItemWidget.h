#ifndef DETTAGLIOPRODOTTOITEMWIDGET_H
#define DETTAGLIOPRODOTTOITEMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <vector>

class OrdineItemWidget : public QWidget
{
    Q_OBJECT
    private:
        QVBoxLayout* mainLayout;
        QHBoxLayout* topLayout;
        QVBoxLayout* bottomLayout;
        QPushButton* btnSubtract;
        QLabel* lblNomeProdotto;
        std::vector<QLabel*> vtrDettagli;

        int index;

        void pulisciBottomLayout();

    public:
        OrdineItemWidget(QWidget *parent = nullptr);
        ~OrdineItemWidget();
        OrdineItemWidget(const OrdineItemWidget& other);
        OrdineItemWidget& operator=(const OrdineItemWidget& other);
        void setNomeProdotto(QString nome);
        void setNomeBottone(QString nome);
        void setDettagliProdotto(QStringList dettagli);
        QPushButton& getBottone()const;

        int getIndex() const;
        void setIndex(int value);

    private slots:
        void buttonTriggered();

    signals:
        void btnClicked(int index);

};

#endif // DETTAGLIOPRODOTTOITEMWIDGET_H

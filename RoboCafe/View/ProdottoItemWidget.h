#ifndef PRODOTTOITEMWIDGET_H
#define PRODOTTOITEMWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QString>

class ProdottoItemWidget : public QWidget
{
    Q_OBJECT
    private:
        QHBoxLayout* mainLayout;
        QPushButton* btnAdd;
        QLabel* lblNomeProdotto;
        int index;
    public:
        ProdottoItemWidget(QWidget *parent = nullptr);
        ~ProdottoItemWidget();
        ProdottoItemWidget(const ProdottoItemWidget& other);
        ProdottoItemWidget& operator=(const ProdottoItemWidget& other);
        void setNomeProdotto(QString nome);
        void setNomeBottone(QString nome);
        QPushButton& getBottone()const;

        int getIndex() const;
        void setIndex(int value);

private slots:
        void buttonTriggered();
signals:
        void btnClicked(int id);
};

#endif // PRODOTTOITEMWIDGET_H

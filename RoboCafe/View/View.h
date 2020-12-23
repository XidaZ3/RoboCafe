#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include "ProdottoItemWidget.h"
#include "DettaglioProdottoItemWidget.h"
#include "ScontrinoItemWidget.h"

class View : public QWidget
{
    Q_OBJECT
    private:
    Vettore<ProdottoItemWidget*> listaProdotti;
    Vettore<DettaglioProdottoItemWidget*> listaProdottiDettagliata;
    Vettore<ScontrinoItemWidget*> listaScontrino;

    void initializeLists();
    
public:
    explicit View(QWidget *parent = nullptr);
    ~View();

signals:

};

#endif // VIEW_H

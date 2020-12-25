#include "mainwindow.h"
#include "View/View.h"
#include "Model/Model.h"
#include "Controller/Controller.h"
#include "Model/Te.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1600,1000);
    View* view = new View(this);
    view->setMinimumWidth(2048);
    view->setMinimumHeight(900);

    Model* m = new Model();
    Controller* c = new Controller();

    c->setModel(m);
    c->setView(view);
    view->setController(c);

    c->inizializzaMenu();

}

MainWindow::~MainWindow()
{
    delete view;
}


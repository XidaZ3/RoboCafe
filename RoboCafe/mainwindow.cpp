#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "View/View.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(1024,768);
    View* view = new View(this);
    view->setMinimumWidth(1024);
    view->setMinimumHeight(768);
}

MainWindow::~MainWindow()
{
    delete view;
}


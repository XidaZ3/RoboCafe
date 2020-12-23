#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "View/View.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(2048,768);
    View* view = new View(this);
    view->setMinimumWidth(2048);
    view->setMinimumHeight(768);
}

MainWindow::~MainWindow()
{
    delete view;
}


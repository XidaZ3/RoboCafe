#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "View/View.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    view = new View(this);
    view->setMinimumWidth(300);
    view->setMinimumHeight(500);
}

MainWindow::~MainWindow()
{
    delete view;
}


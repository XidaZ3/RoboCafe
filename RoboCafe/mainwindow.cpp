#include "mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "View/View.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    View* view = new View(this);
    view->setMinimumWidth(300);
    view->setMinimumHeight(500);
    layout()->addWidget(view);
}

MainWindow::~MainWindow()
{
}


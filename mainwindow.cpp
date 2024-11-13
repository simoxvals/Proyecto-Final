#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ventana(new Ventana())
{
    ventana->show();
    this->close();
}

MainWindow::~MainWindow()
{
    delete ventana;
}

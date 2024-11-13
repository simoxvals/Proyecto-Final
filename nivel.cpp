#include "nivel.h"
#include "nivel1.h"
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QPixmap>
#include <QDebug>

NivelWindow::NivelWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Seleccionar Nivel");
    setFixedSize(800, 600);

    fondo = new QLabel(this);
    fondo->setScaledContents(true);
    fondo->setGeometry(this->rect());

    QPixmap pixmap(":/inicio2.jpg");
    fondo->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding));

    botonNivel1 = new QPushButton("Nivel 1", this);
    botonNivel1->setGeometry(300, 400, 100, 50);
    botonNivel1->setStyleSheet("background-color: #FF8C00; color: white; font-weight: bold;");
    connect(botonNivel1, &QPushButton::clicked, this, &NivelWindow::jugarNivel1);

    botonNivel2 = new QPushButton("Nivel 2", this);
    botonNivel2->setGeometry(450, 400, 100, 50);
    botonNivel2->setStyleSheet("background-color: #FF8C00; color: white; font-weight: bold;");
    connect(botonNivel2, &QPushButton::clicked, this, &NivelWindow::jugarNivel2);
}

void NivelWindow::jugarNivel1()
{

    Nivel1 *nivel1 = new Nivel1();
    nivel1->show();
    this->close();
}

void NivelWindow::jugarNivel2()
{

    qDebug("Se ha seleccionado el Nivel 2");
    this->close();
}

NivelWindow::~NivelWindow()
{

}

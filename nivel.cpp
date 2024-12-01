#include "nivel.h"

NivelWindow::NivelWindow()
{
    fondo = new QLabel(this);
    QPixmap pixmap(":/inicio2.jpg");
    fondo->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding));

    botonNivel1 = new QPushButton("Nivel 1", this);
    botonNivel1->setGeometry(500, 300, 100, 50);
    connect(botonNivel1, &QPushButton::clicked, this, &NivelWindow::jugarNivel1);

    botonNivel2 = new QPushButton("Nivel 2", this);
    botonNivel2->setGeometry(600,300, 100, 50);
    connect(botonNivel2, &QPushButton::clicked, this, &NivelWindow::jugarNivel2);
}

void NivelWindow::resizeEvent(QResizeEvent *event)
{
    fondo->setGeometry(this->rect());
    fondo->setPixmap(QPixmap(":/inicio2.jpg").scaled(this->size(), Qt::KeepAspectRatioByExpanding));
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


#include "hacha.h"

Hacha::Hacha(int xInicial, int yInicial, float velocidadX, float velocidadY) : velocidadX(velocidadX), velocidadY(velocidadY), eliminada(false), indiceImagen(0)
{
    imagenesGiro = {":/hacha1.png", ":/hacha2.png", ":/hacha3.png", ":/hacha4.png"};

    QPixmap pixmap(imagenesGiro[indiceImagen]);
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    setPixmap(pixmap);
    setPos(xInicial, yInicial);

    movimientoTimer = new QTimer(this);
    connect(movimientoTimer, &QTimer::timeout, this, &Hacha::mover);
    movimientoTimer->start(30);

    animacionTimer = new QTimer(this);
    connect(animacionTimer, &QTimer::timeout, this, &Hacha::animarGiro);
    animacionTimer->start(100);
}

void Hacha::mover()
{
    setPos(x() + velocidadX, y() + velocidadY);

}

void Hacha::animarGiro()
{
    indiceImagen = (indiceImagen + 1) % imagenesGiro.size();
    QPixmap pixmap(imagenesGiro[indiceImagen]);
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    setPixmap(pixmap);
}



// hacha.cpp
#include "hacha.h"
#include <QGraphicsScene>

Hacha::Hacha(int xInicial, int yInicial, int velocidadX, int velocidadY)
    : velocidadX(velocidadX), velocidadY(velocidadY), eliminada(false) {
    QPixmap pixmap(":/hacha.png");
    pixmap = pixmap.scaled(30, 30, Qt::KeepAspectRatio);
    setPixmap(pixmap);
    setPos(xInicial, yInicial);

    movimientoTimer = new QTimer(this);
    connect(movimientoTimer, &QTimer::timeout, this, &Hacha::mover);
    movimientoTimer->start(30);
}

Hacha::~Hacha() {
    if (movimientoTimer) {
        movimientoTimer->stop();
        delete movimientoTimer;
    }
}

void Hacha::mover() {
    if (!eliminada) {
        setPos(x() + velocidadX, y() + velocidadY);


        if (x() < 0 || x() > 800 || y() < 0 || y() > 600) {
            eliminada = true;
            scene()->removeItem(this);
            delete this;
        }
    }
}



#include "fuego.h"
#include <QGraphicsScene>

fuego::fuego(int xInicial, int yInicial, float velocidadX, float velocidadY) : velocidadX(velocidadX), velocidadY(velocidadY), eliminada(false)
{

    QPixmap pixmap(":/fuego.png");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    setPixmap(pixmap);
    setPos(xInicial, yInicial);

    movimientoTimer = new QTimer(this);
    connect(movimientoTimer, &QTimer::timeout, this, &fuego::mover);
    movimientoTimer->start(30);

}

void fuego::mover()
{
    if (!eliminada)
    {
        float movimientoX = velocidadX;
        float movimientoY = velocidadY + 20 * std::sin(x());
        setPos(x() + movimientoX, y() + movimientoY);
    }
}


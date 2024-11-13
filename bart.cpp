#include "bart.h"
#include <QPixmap>

Bart::Bart(int x, int y, QObject *parent)
    : Personaje(x, y, 100, parent)
{
    QPixmap pixmap(":/bart.png");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    setPixmap(pixmap);
}

void Bart::mover()
{
    if (x() < 750)
    {   velocidad += 1;
        setPos(x() + velocidad, y());
    }
}

void Bart::golpear() {
    recibirGolpe();
    aplicarEmpuje(-15, -10);
}

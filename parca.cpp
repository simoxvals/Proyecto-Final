// parca.cpp
#include "parca.h"
#include "hacha.h"
#include <cmath>

Parca::Parca(int x, int y, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem() {
    QPixmap pixmap(":/parca.png");
    pixmap = pixmap.scaled(50, 50, Qt::KeepAspectRatio);
    setPixmap(pixmap);
    setPos(x, y);
}

Hacha* Parca::lanzarHacha(int objetivoX, int objetivoY) {
    int dx = objetivoX - x();
    int dy = objetivoY - y();
    float magnitud = std::sqrt(dx * dx + dy * dy);

    if (magnitud == 0) {
        return nullptr;
    }
    int velocidadX = static_cast<int>((dx / magnitud) * 10);
    int velocidadY = static_cast<int>((dy / magnitud) * 10);

    Hacha *hacha = new Hacha(x(), y(), velocidadX, velocidadY);

    if (!scene()->items().contains(hacha)) {
        scene()->addItem(hacha);
        hachasLanzadas.append(hacha);
    }

    return hacha;
}

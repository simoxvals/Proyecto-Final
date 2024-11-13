#include "objeto.h"

Objeto::Objeto(int x, int y, QObject *parent)
    : QObject(parent), QGraphicsPixmapItem() {
    setPos(x, y);
}

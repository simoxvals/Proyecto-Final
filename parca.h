#ifndef PARCA_H
#define PARCA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QList>
#include "hacha.h"

class Parca : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    Parca(int x, int y, QObject *parent = nullptr);
    Hacha* lanzarHacha(int xObjetivo, int yObjetivo);
    QList<Hacha*> hachasLanzadas;
};

#endif // PARCA_H

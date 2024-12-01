#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsPixmapItem>

class Objeto : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    Objeto(int x, int y);
};

#endif



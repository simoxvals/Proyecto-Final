#ifndef OBJETO_H
#define OBJETO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Objeto : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    explicit Objeto(int x, int y, QObject *parent = nullptr);

    virtual void aparecer() = 0;
    virtual void desaparecer() = 0;
};

#endif



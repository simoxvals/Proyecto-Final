#ifndef FUEGO_H
#define FUEGO_H

#include <QMainWindow>
#include<QTimer>
#include <QGraphicsPixmapItem>
#include <QStringList>

class fuego : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    fuego(int xInicial, int yInicial, float velocidadX, float velocidadY);
    void mover();
    float getVelocidadX() const { return velocidadX; }

private:
    float velocidadX;
    float velocidadY;
    bool eliminada;
    QTimer *movimientoTimer;
};

#endif // FUEGO_H

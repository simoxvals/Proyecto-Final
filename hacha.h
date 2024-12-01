#ifndef HACHA_H
#define HACHA_H

#include <QGraphicsPixmapItem>
#include <QTimer>



class Hacha : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Hacha(int xInicial, int yInicial, float velocidadX, float velocidadY);
    float getVelocidadX() const { return velocidadX; }
    void mover();
    void animarGiro();

private:
    float velocidadX;
    float velocidadY;
    int indiceImagen;
    bool eliminada;
    QTimer *animacionTimer;
    QTimer *movimientoTimer;
    QStringList imagenesGiro;

};

#endif // HACHA_H

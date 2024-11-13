// hacha.h
#ifndef HACHA_H
#define HACHA_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class Hacha : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Hacha(int xInicial, int yInicial, int velocidadX, int velocidadY);
    ~Hacha();

    void mover();
    bool isEliminada() const { return eliminada; }
private:
    int velocidadX;
    int velocidadY;
    QTimer *movimientoTimer;
    bool eliminada;
};

#endif // HACHA_H

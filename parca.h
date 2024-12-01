#ifndef PARCA_H
#define PARCA_H

#include "personaje.h"
#include "hacha.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <cmath>
#include <cstdlib>
#include <ctime>


class Parca : public Personaje
{
    Q_OBJECT

public:
    Parca(int,int);
    Hacha* lanzarHacha(int,int);
    QList<Hacha*> hachasLanzadas;
    QTimer *movimientoTimer;
    void reducirVida(float);
    float getVida() const;

public slots:
    void moverAleatoriamente();

private:
    float vida;
    QGraphicsRectItem *barraVida;
    QMediaPlayer *HachaS;

};

#endif // PARCA_H

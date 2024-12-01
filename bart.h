#ifndef BART_H
#define BART_H

#include "personaje.h"
#include "fuego.h"
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QAudioOutput>

class Bart : public Personaje
{
    Q_OBJECT

public:
    Bart(int,int);
    QList<fuego*> fuegosLanzados;
    fuego* lanzarFuego(int,int);
    QTimer *animacionTimer;
    void cambiarSprite(const QString&);
    void mover();
    void stop();
    void puentes();
    void reducirVida(float);
    void golpear(int);
    void iniciarAnimacionGiro(int);
    float getVida() const;
    void resetearImagen();
    void detenerAnimacion();

public slots:
    void animarGiro();

private:
    float vida;
    QGraphicsRectItem *barraVida;
    QStringList imagenesGiro;
    int indiceImagen;
    QMediaPlayer *FuegoS;
    QMediaPlayer *GolpeS;
};

#endif // BART_H

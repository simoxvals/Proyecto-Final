#include "personaje.h"

Personaje::Personaje(int x, int y, int salud) : QGraphicsPixmapItem(), salud(salud), velocidad(10), velocidadY(0), enSuelo(true)
{
    setPos(x, y);

    saltoTimer = new QTimer(this);
    connect(saltoTimer, &QTimer::timeout, this, &Personaje::actualizarSalto);

    retrocesoTimer = new QTimer(this);
    connect(retrocesoTimer, &QTimer::timeout, this, &Personaje::actualizarRetroceso);
}

void Personaje::reducirSalud(int cantidad)
{
    salud -= cantidad;
}

int Personaje::getSalud() const
{
    return salud;
}

void Personaje::saltar()
{
    if (enSuelo || enElPuente)
    {
        velocidadY = -20;
        enSuelo = false;
        enElPuente = false;
        saltoTimer->start(30);
    }
}


void Personaje::actualizarSalto()
{
    setPos(x(), y() + velocidadY);
    velocidadY += 2;

    if (y() >= 480)
    {
        setPos(x(), 480);
        enSuelo = true;
        velocidadY = 0;
        saltoTimer->stop();
    }
}

void Personaje::aplicarEmpuje(int fuerzaX, int fuerzaY)
{
    velocidad = fuerzaX;
    velocidadY = fuerzaY;
}

void Personaje::recibirGolpe()
{
    velocidadY = -15;
    velocidad = -10;
    retrocesoTimer->start(30);
}

void Personaje::actualizarRetroceso()
{
    setPos(x() + velocidad, y() + velocidadY);
    velocidadY += 2;

    if (y() >= 480)
    {
        setPos(x(), 480);
        velocidad = 10;
        velocidadY = 0;
        retrocesoTimer->stop();
    }
}

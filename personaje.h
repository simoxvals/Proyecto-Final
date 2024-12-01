#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Personaje : public QObject, public QGraphicsPixmapItem

{
    Q_OBJECT

public:
    Personaje(int x, int y, int salud);

    void saltar();
    void recibirGolpe();
    void aplicarEmpuje(int fuerzaX, int fuerzaY);
    void reducirSalud(int cantidad);
    bool enSuelo;
    bool enElPuente;
    int getSalud() const;
    int getVelocidad() const { return velocidad; }
    int salud;
    int velocidad;
    int velocidadY;
    QTimer *saltoTimer;
    QTimer *retrocesoTimer;


public slots:
    void actualizarSalto();
    void actualizarRetroceso();
};

#endif // PERSONAJE_H

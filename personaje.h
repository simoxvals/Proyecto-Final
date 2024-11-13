#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Personaje : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Personaje(int x, int y, int salud, QObject *parent = nullptr);
    void reducirSalud(int cantidad);
    int getSalud() const;
    int getVelocidad() const { return velocidad; }
    void saltar();
    void recibirGolpe();
    void aplicarEmpuje(int fuerzaX, int fuerzaY);
    bool enSuelo;

protected:
    int salud;
    int velocidad;
    int velocidadY;
    bool golpeado;

    QTimer *saltoTimer;
    QTimer *retrocesoTimer;

public slots:
    void actualizarSalto();
    void actualizarRetroceso();
};

#endif // PERSONAJE_H

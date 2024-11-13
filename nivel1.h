#ifndef NIVEL1_H
#define NIVEL1_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "bart.h"
#include "parca.h"
#include "gema.h"
#include <QLabel>
#include <QGraphicsScene>
#include <QKeyEvent>

class Nivel1 : public QWidget {
    Q_OBJECT

public:
    explicit Nivel1(QWidget *parent = nullptr);
    ~Nivel1();

private slots:
    void verificarColisiones();
    void finalizarNivel();

public slots:
    void lanzarHacha();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    Bart *bart;
    Parca *parca;
    QList<Gema*> gemas;
    QTimer *timer;
    int gemasRecolectadas;
    void inicializarEscena();
    double velocidadY;
    double gravedad;
    bool enSuelo;
    QTimer *timerLanzamientoHachas;
    QTimer *hachaTimer;
};

#endif // NIVEL1_H


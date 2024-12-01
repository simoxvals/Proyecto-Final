#ifndef NIVEL1_H
#define NIVEL1_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "logindialog.h"
#include "bart.h"
#include "parca.h"
#include "gema.h"
#include "hacha.h"


class Nivel1 : public QMainWindow
{
    Q_OBJECT

public:
    Nivel1();
    void keyPressEvent(QKeyEvent *event);
    void inicializarEscena();

public slots:
    void verificarColisiones();
    void finalizarNivelgemas();
    void finalizarNivelhachas();
    void finalizarNivelfuegos();
    void lanzarHacha();
    void lanzarFuego();

private:
    Bart *bart;
    Parca *parca;
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsRectItem *suelo;
    QGraphicsTextItem* puntajeTexto;
    QTimer *timerColisiones;
    QTimer *timerLanzamientoHachas;
    QMediaPlayer *ParcaS;
    QMediaPlayer *GemaS;
    QList<Gema*> gemas;
    QList <QGraphicsRectItem*> paredes;
    QList <QGraphicsRectItem*> puentes;
    QVector<QGraphicsPixmapItem*> gemasRecolectadasImagenes;
    int gemasRecolectadas;
    int puntaje;
    double velocidadY;
    double gravedad;
    bool enSuelo;

};

#endif // NIVEL1_H

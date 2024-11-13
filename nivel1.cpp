#include "nivel1.h"
#include "bart.h"
#include "parca.h"
#include "gema.h"
#include "hacha.h"
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>

Nivel1::Nivel1(QWidget *parent)
    : QWidget(parent), gemasRecolectadas(0)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setFixedSize(800, 600);
    setFixedSize(800, 600);

    inicializarEscena();
    bart = new Bart(100, 500);
    scene->addItem(bart);

    parca = new Parca(700, 500);
    scene->addItem(parca);

    Gema *gema1 = new Gema(300, 400);
    scene->addItem(gema1);
    gemas.append(gema1);

    Gema *gema2 = new Gema(400, 400);
    scene->addItem(gema2);
    gemas.append(gema2);

    Gema *gema3 = new Gema(500, 400);
    scene->addItem(gema3);
    gemas.append(gema3);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Nivel1::verificarColisiones);
    timer->start(100);

    timerLanzamientoHachas = new QTimer(this);
    connect(timerLanzamientoHachas, &QTimer::timeout, this, &Nivel1::lanzarHacha);
    timerLanzamientoHachas->start(3100);
}

Nivel1::~Nivel1() {
    delete timer;
    delete timerLanzamientoHachas;
}

void Nivel1::lanzarHacha() {
    int objetivoX = bart->x();
    int objetivoY = bart->y();

    Hacha* hacha = parca->lanzarHacha(objetivoX, objetivoY);
    if (hacha != nullptr) {
        scene->addItem(hacha);
    }
}


void Nivel1::inicializarEscena() {

    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem();
    QPixmap imagenFondo(":/fondo.jpg");
    imagenFondo = imagenFondo.scaled(800, 600, Qt::KeepAspectRatioByExpanding);
    fondo->setPixmap(imagenFondo);
    fondo->setZValue(-1);
    scene->addItem(fondo);

    QGraphicsRectItem *suelo = new QGraphicsRectItem(0, 550, 800, 50);
    suelo->setBrush(QColor(139, 69, 19));
    suelo->setZValue(0);
    scene->addItem(suelo);
}

void Nivel1::keyPressEvent(QKeyEvent *event) {

    if (event->key() == Qt::Key_W) {
        bart->saltar();
    } else if (event->key() == Qt::Key_A) {
        bart->setPos(bart->x() - bart->getVelocidad(), bart->y());
    } else if (event->key() == Qt::Key_D) {
        bart->setPos(bart->x() + bart->getVelocidad(), bart->y());
    }
}

void Nivel1::verificarColisiones() {
    for (int i = 0; i < gemas.size(); ++i) {
        if (bart->collidesWithItem(gemas[i])) {
            scene->removeItem(gemas[i]);
            delete gemas[i];
            gemas.removeAt(i);
            gemasRecolectadas++;
        }
    }

    for (int i = 0; i < parca->hachasLanzadas.size(); ++i) {
        Hacha *hacha = parca->hachasLanzadas[i];

        if (bart->collidesWithItem(hacha) && !hacha->isEliminada()) {
            bart->golpear();
            scene->removeItem(hacha);
            delete hacha;
            parca->hachasLanzadas.removeAt(i);
            --i;
        }
    }

    if (bart->collidesWithItem(parca)) {
        bart->golpear();
    }

    if (gemas.isEmpty()) {
        finalizarNivel();
    }
}

void Nivel1::finalizarNivel() {
    QMessageBox::information(this, "Nivel Completado", "¡Felicidades! Has recolectado todas las gemas.");
    close();
}



#include "nivel1.h"


Nivel1::Nivel1() :  gemasRecolectadas(0), puntaje(0)
{
    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    view->setFixedSize(1100,600);
    setFixedSize(1100, 600);

    inicializarEscena();

    bart = new Bart(100,480);
    scene->addItem(bart);

    parca = new Parca(500, 200);
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

    Gema *gema4 = new Gema(615, 350);
    scene->addItem(gema4);
    gemas.append(gema4);

    Gema *gema5 = new Gema(715,300);
    scene->addItem(gema5);
    gemas.append(gema5);

    Gema *gema6 = new Gema(815, 300);
    scene->addItem(gema6);
    gemas.append(gema6);

    Gema *gema7 = new Gema(900, 350);
    scene->addItem(gema7);
    gemas.append(gema7);

    Gema *gema8 = new Gema(200, 400);
    scene->addItem(gema8);
    gemas.append(gema8);

    Gema *gema9 = new Gema(1000,390);
    scene->addItem(gema9);
    gemas.append(gema9);

    Gema *gema10 = new Gema(750,390);
    scene->addItem(gema10);
    gemas.append(gema10);

    ParcaS = new QMediaPlayer(this);
    QAudioOutput *audioP = new QAudioOutput(this);
    audioP->setVolume(0.7);
    ParcaS->setAudioOutput(audioP);
    ParcaS->setSource(QUrl("qrc:/parcaS.mp3"));

    GemaS = new QMediaPlayer(this);
    QAudioOutput *audioG = new QAudioOutput(this);
    audioG->setVolume(0.7);
    GemaS->setAudioOutput(audioG);
    GemaS->setSource(QUrl("qrc:/gemaS.mp3"));

    timerColisiones = new QTimer(this);
    connect(timerColisiones, &QTimer::timeout, this, &Nivel1::verificarColisiones);
    timerColisiones->start(10);

    timerLanzamientoHachas = new QTimer(this);
    connect(timerLanzamientoHachas, &QTimer::timeout, this, &Nivel1::lanzarHacha);
    timerLanzamientoHachas->start(4000);
}

void Nivel1::lanzarHacha()
{
    int objetivoX = bart->x();
    int objetivoY = bart->y();

    Hacha* hacha = parca->lanzarHacha(objetivoX, objetivoY);
    if (hacha != nullptr)
    {
        scene->addItem(hacha);
    }
}

void Nivel1::lanzarFuego()
{
    int objetivoX = parca->x();
    int objetivoY = parca->y();

    fuego* Fuego = bart->lanzarFuego(objetivoX, objetivoY);
    if (Fuego != nullptr)
    {
        scene->addItem(Fuego);
    }
}
void Nivel1::inicializarEscena() {

    QGraphicsPixmapItem* fondo = new QGraphicsPixmapItem();
    QPixmap imagenFondo(":/fondo.jpg");
    imagenFondo = imagenFondo.scaled(1100, 600, Qt::KeepAspectRatioByExpanding);
    fondo->setPixmap(imagenFondo);
    scene->addItem(fondo);

    puntajeTexto = new QGraphicsTextItem();
    puntajeTexto->setPlainText("Gemas recolectadas: 0 de 10");
    puntajeTexto->setDefaultTextColor(Qt::black);
    puntajeTexto->setFont(QFont("Algerian", 10));
    puntajeTexto->setPos(60, 50);
    scene->addItem(puntajeTexto);

    suelo = new QGraphicsRectItem(0,570, 1100, 50);
    suelo->setBrush(Qt::darkGray);
    scene->addItem(suelo);

    QGraphicsRectItem *paredIzquierda = new QGraphicsRectItem(0, 0, 50, 600);
    paredIzquierda->setBrush(Qt::darkGray);
    paredes.append(paredIzquierda);
    scene->addItem(paredIzquierda);

    QGraphicsRectItem *paredDerecha = new QGraphicsRectItem(1100, 0, 50, 600);
    paredDerecha->setBrush(Qt::darkGray);
    paredes.append(paredDerecha);
    scene->addItem(paredDerecha);

    QGraphicsRectItem *paredSuperior = new QGraphicsRectItem(0, 0,1100, 50);
    paredSuperior->setBrush(Qt::darkGray);
    paredes.append(paredSuperior);
    scene->addItem(paredSuperior);

    QGraphicsRectItem *puente1 = new QGraphicsRectItem(600, 520, 100, 10);
    puente1->setBrush(Qt::darkGray);
    puentes.append(puente1);
    scene->addItem(puente1);

    QGraphicsRectItem *puente2 = new QGraphicsRectItem(700,480, 100, 10);
    puente2->setBrush(Qt::darkGray);
    puentes.append(puente2);
    scene->addItem(puente2);

    QGraphicsRectItem *puente3 = new QGraphicsRectItem(800,520, 100, 10);
    puente3->setBrush(Qt::darkGray);
    puentes.append(puente3);
    scene->addItem(puente3);


}

void Nivel1::keyPressEvent(QKeyEvent *event)
{

    if (event->key() == Qt::Key_W)
    {
        bart->saltar();
    } else if (event->key() == Qt::Key_A)
    {
        bart->cambiarSprite(":/bartI.png");
        bart->setPos(bart->x() - bart->getVelocidad()*1.8, bart->y());

    } else if (event->key() == Qt::Key_D)
    {   bart->cambiarSprite(":/bart.png");
        bart->setPos(bart->x() + bart->getVelocidad()*1.8, bart->y());

    } else if (event->key() == Qt::Key_Space)
    {
        lanzarFuego();
    }

}

void Nivel1::verificarColisiones()
{

    for (int i = 0; i < gemas.size(); ++i)
    {
        if (bart->collidesWithItem(gemas[i]))
        {
            GemaS -> play();
            scene->removeItem(gemas[i]);
            delete gemas[i];
            gemas.removeAt(i);
            gemasRecolectadas++;

            puntaje += 1;
            puntajeTexto->setPlainText("Gemas recolectadas: " + QString::number(puntaje) + " de 10");

            QGraphicsPixmapItem* gemaImagen = new QGraphicsPixmapItem(QPixmap(":/gema.png").scaled(20, 20, Qt::KeepAspectRatio));
            gemaImagen->setPos(60 + (gemasRecolectadasImagenes.size() * 25), 35);
            scene->addItem(gemaImagen);

            gemasRecolectadasImagenes.append(gemaImagen);

            if (puntaje == 10)
            {
                finalizarNivelgemas();
            }
        }
    }

    for (int j = 0; j < paredes.size(); ++j)
    {
        if (bart->collidesWithItem(paredes[j]))
        {
            bart->stop();
            break;
        }
    }

    for (int k = 0; k < puentes.size(); ++k)
    {
        if (bart->collidesWithItem(puentes[k]))
        {
            qDebug() << "Colisión detectada con puente";
            bart->puentes();
            break;
        }

    }

    for (int i = 0; i < bart->fuegosLanzados.size(); ++i)
    {
        fuego *Fuego = bart->fuegosLanzados[i];

        if (Fuego->collidesWithItem(parca))
        {
            ParcaS -> play();
            scene->removeItem(Fuego);
            delete Fuego;
            bart->fuegosLanzados.removeAt(i);
            --i;

            parca->reducirVida(2.0);

            if (parca->getVida() <= 0.0)
            {
                finalizarNivelfuegos();
                return;
            }
        }
        else if (Fuego->collidesWithItem(suelo))
        {
            scene->removeItem(Fuego);
            delete Fuego;
            bart->fuegosLanzados.removeAt(i);
            --i;
        }
        else
        {
            for (int j = 0; j < paredes.size(); ++j)
            {
                if (Fuego->collidesWithItem(paredes[j]))
                {
                    scene->removeItem(Fuego);
                    delete Fuego;
                    bart->fuegosLanzados.removeAt(i);
                    --i;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < parca->hachasLanzadas.size(); ++i)
    {
        Hacha *hacha = parca->hachasLanzadas[i];

        if (bart->collidesWithItem(hacha))
        {
            int direccionImpacto = (hacha->getVelocidadX() > 0) ? 1 : -1;
            bart->golpear(direccionImpacto);
            bart->iniciarAnimacionGiro(500);

            scene->removeItem(hacha);
            delete hacha;
            parca->hachasLanzadas.removeAt(i);
            --i;

            bart ->reducirVida(20.0);

            if (bart->getVida() <= 0.0)
            {
                finalizarNivelhachas();
                return;
            }
        }
        else if(hacha -> collidesWithItem(suelo))
        {
            scene->removeItem(hacha);
            delete hacha;
            parca->hachasLanzadas.removeAt(i);
            i--;
        }
        else
        {
            for (int j = 0; j < paredes.size(); ++j)
            {
                if (hacha->collidesWithItem(paredes[j]))
                {
                    scene->removeItem(hacha);
                    delete hacha;
                    parca->hachasLanzadas.removeAt(i);
                    --i;
                    break;
                }
            }
        }
    }

    if (bart->collidesWithItem(parca))
    {
        int direccionGolpe = (bart->x() < parca->x()) ? -1 : 1;
        bart->golpear(direccionGolpe);
    }
}

void Nivel1::finalizarNivelgemas()
{
    for (QGraphicsPixmapItem* gemaImagen : gemasRecolectadasImagenes)
    {
        scene->removeItem(gemaImagen);
        delete gemaImagen;
    }
    gemasRecolectadasImagenes.clear();
    QMessageBox::information(this, "Nivel Completado", "¡Felicidades " + LoginDialog::usuarioGlobal +"! Has recolectado todas las gemas.");
    this->close();
}

void Nivel1::finalizarNivelhachas()
{
    for (QGraphicsPixmapItem* gemaImagen : gemasRecolectadasImagenes)
    {
        scene->removeItem(gemaImagen);
        delete gemaImagen;
    }
    gemasRecolectadasImagenes.clear();
    QMessageBox::information(this, "Nivel perdido","Lo siento " + LoginDialog::usuarioGlobal +", Te ha eliminado la Parca con sus hachas");
    this -> close();
}

void Nivel1::finalizarNivelfuegos()
{
    for (QGraphicsPixmapItem* gemaImagen : gemasRecolectadasImagenes)
    {
        scene->removeItem(gemaImagen);
        delete gemaImagen;
    }
    gemasRecolectadasImagenes.clear();
    QMessageBox::information(this, "Nivel Completado", "¡Felicidades " + LoginDialog::usuarioGlobal + "! Has eliminado a la Parca con tus Fuegos");
    this-> close();
}



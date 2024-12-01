#include "bart.h"

Bart::Bart(int x, int y) : Personaje(x, y, 100), vida(100.0),indiceImagen(0)
{
    QPixmap pixmap(":/bart.png");
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(pixmap);

    barraVida = new QGraphicsRectItem(this);
    barraVida->setRect(0, -10, 100, 5);
    barraVida->setBrush(Qt::green);

    FuegoS = new QMediaPlayer(this);
    QAudioOutput *audioF = new QAudioOutput(this);
    audioF->setVolume(0.7);
    FuegoS->setAudioOutput(audioF);
    FuegoS->setSource(QUrl("qrc:/fuegoS.mp3"));

    GolpeS = new QMediaPlayer(this);
    QAudioOutput *audioG = new QAudioOutput(this);
    audioG->setVolume(0.7);
    GolpeS->setAudioOutput(audioG);
    GolpeS->setSource(QUrl("qrc:/golpeS.mp3"));

    imagenesGiro = {":/bart.png", ":/bart1golpe.png", ":/bart2golpe.png", ":/bart3golpe.png"};
    animacionTimer = new QTimer(this);
    connect(animacionTimer, &QTimer::timeout, this, &Bart::animarGiro);
}

void Bart::iniciarAnimacionGiro(int duracionMs)
{
    animacionTimer->start(100);
    QTimer::singleShot(duracionMs, this, &Bart::detenerAnimacion);
}

void Bart::detenerAnimacion()
{
    animacionTimer->stop();
    resetearImagen();
}

void Bart::animarGiro()
{
    indiceImagen = (indiceImagen + 1) % imagenesGiro.size();
    QPixmap pixmap(imagenesGiro[indiceImagen]);
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(pixmap);
}

void Bart::resetearImagen()
{
    QPixmap pixmap(imagenesGiro[0]);
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(pixmap);
    indiceImagen = 0;
}

void Bart::mover()
{

    if (x() < 1100 && velocidadY == 0)
    {
        velocidad += 8;
        setPos(x() + velocidad, y());
    }
}

float Bart::getVida() const
{
    return vida;
}

void Bart::reducirVida(float cantidad)
{
    vida -= cantidad;
    float porcentajeVida = vida / 100.0;
    barraVida->setRect(0, -10, 100 * porcentajeVida, 5);

    if (porcentajeVida > 0.7)
    {
        barraVida->setBrush(Qt::green);
    } else if (porcentajeVida > 0.3)
    {
        barraVida->setBrush(Qt::yellow);
    } else {
        barraVida->setBrush(Qt::red);
    }

    if (vida <= 0)
    {
        QGraphicsPixmapItem *imagenFinal = new QGraphicsPixmapItem(QPixmap(":/losing.png").scaled(800, 800, Qt::KeepAspectRatio));
        imagenFinal->setPos(200, 180);
        scene()->addItem(imagenFinal);
        this -> hide();
    }
}

void Bart::cambiarSprite(const QString &rutaImagen)
{
    QPixmap pixmap(rutaImagen);
    pixmap = pixmap.scaled(100, 100, Qt::KeepAspectRatio);
    setPixmap(pixmap);
}

fuego* Bart::lanzarFuego(int objetivoX, int objetivoY)
{
    FuegoS->play();

    int dx = objetivoX - x();
    int dy = objetivoY - y();
    float magnitud = std::sqrt(dx * dx + dy * dy);
    if (magnitud == 0)
    {
        return nullptr;
    }

    float velocidadX = (dx / magnitud) * 20;
    float  velocidadY = (dy / magnitud) * 20;

    fuego *Fuego = new fuego(x(), y(), velocidadX, velocidadY);
    scene()->addItem(Fuego);
    fuegosLanzados.append(Fuego);
    return Fuego;
}

void Bart::golpear(int direccionX)
{
    GolpeS-> play();
    velocidadY = -15;
    velocidad = direccionX * 10;
    retrocesoTimer->start(30);
}


void Bart::stop()
{
    if (x() <= 50)
    {
        int retroceso = 10;
        setPos(x() + retroceso, y());
        int temp = velocidad;
        velocidad = -velocidad / 2;
        velocidad = temp;
    }

    else if (x() >= 750)
    {
        int retroceso = -10;
        setPos(x() + retroceso, y());
        int temp = velocidad;
        velocidad = -velocidad / 2;
        velocidad = temp;
    }
}

void Bart::puentes()
{
    QList<QGraphicsItem *> colisiones = collidingItems();
    bool sobrePuente = false;
    for (auto *item : colisiones)
    {
        QGraphicsRectItem *puente = dynamic_cast<QGraphicsRectItem *>(item);
        if (puente)
        {
            QRectF puenteRect = puente->boundingRect().translated(puente->pos());
            QRectF bartRect = boundingRect().translated(pos());
            if (velocidadY > 0)
            {
                if (bartRect.bottom() <= puenteRect.top() &&
                    bartRect.right() >= puenteRect.left() &&
                    bartRect.left() <= puenteRect.right())
                {
                    setPos(x(), puenteRect.top() - bartRect.height());
                    velocidadY = 0;
                    sobrePuente = true;
                    enElPuente = true;
                    break;
                }
            }

            if (bartRect.bottom() > puenteRect.top() && bartRect.top() < puenteRect.bottom())
            {
                if (bartRect.right() > puenteRect.left() && bartRect.left() < puenteRect.left())
                {
                    setPos(puenteRect.left() - bartRect.width(), y());
                    continue;
                }
                else if (bartRect.left() < puenteRect.right() && bartRect.right() > puenteRect.right())
                {
                    setPos(puenteRect.right(), y());
                    continue;
                }
            }

            if (bartRect.top() < puenteRect.bottom() && bartRect.bottom() > puenteRect.top() && velocidadY > 0)
            {
                setPos(x(), puenteRect.top() - bartRect.height());
                velocidadY = 0;
                sobrePuente = true;
                enElPuente = true;
                break;
            }
        }
    }

    if (!sobrePuente)
    {
        enElPuente = false;
    }
}




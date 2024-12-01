#include "parca.h"

Parca::Parca(int x, int y) : Personaje(x, y, 100), vida(100)
{
    QPixmap pixmap(":/parca.png");
    pixmap = pixmap.scaled(120, 120, Qt::KeepAspectRatio);
    setPixmap(pixmap);
    setPos(x, y);

    barraVida = new QGraphicsRectItem(this);
    barraVida->setRect(0, -10, 120, 5);
    barraVida->setBrush(Qt::green);

    HachaS = new QMediaPlayer(this);
    QAudioOutput *audioOutput = new QAudioOutput(this);
    audioOutput->setVolume(0.7);
    HachaS->setAudioOutput(audioOutput);
    HachaS->setSource(QUrl("qrc:/hachasonido.mp3"));

    movimientoTimer = new QTimer(this);
    connect(movimientoTimer, &QTimer::timeout, this, &Parca::moverAleatoriamente);
    movimientoTimer->start(100);

    std::srand(std::time(nullptr));
}

Hacha* Parca::lanzarHacha(int objetivoX, int objetivoY)
{
    HachaS->play();

    int dx = objetivoX - x();
    int dy = objetivoY - y();
    float magnitud = std::sqrt(dx * dx + dy * dy);

    if (magnitud == 0){ return nullptr;}

    float velocidadX = (dx / magnitud) * 20;
    float velocidadY = (dy / magnitud) * 20;

    Hacha *hacha = new Hacha(x(), y(), velocidadX, velocidadY);
    scene()->addItem(hacha);
    hachasLanzadas.append(hacha);
    return hacha;
}

void Parca::reducirVida(float cantidad)
{
    vida -= cantidad;
    float porcentajeVida = vida / 100.0;
    barraVida->setRect(0, -10, 100 * porcentajeVida, 5);

    if (porcentajeVida > 0.7) {
        barraVida->setBrush(Qt::green);
    } else if (porcentajeVida > 0.3) {
        barraVida->setBrush(Qt::yellow);
    } else {
        barraVida->setBrush(Qt::red);
    }

    if (vida <= 0)
    {
        QGraphicsPixmapItem *imagenFinal = new QGraphicsPixmapItem(QPixmap(":/victory.png"));
        imagenFinal->setPos(this->x(), this->y());
        scene()->addItem(imagenFinal);
        this->hide();
    }
}


float Parca::getVida() const
{
    return vida;
}

void Parca::moverAleatoriamente()
{
    static int contador = 0;
    static int direccionX = 0;
    static int direccionY = 0;

    if (contador % 10 == 0)
    {
        direccionX = (std::rand() % 41) - 20;
        direccionY = (std::rand() % 41) - 20;
    }

    contador++;

    int nuevoX = x() + direccionX;
    int nuevoY = y() + direccionY;

    if (scene())
    {
        if (nuevoX < 50) nuevoX = 50;
        if (nuevoX >= scene()->width() - pixmap().width() - 50) nuevoX = scene()->width() - pixmap().width() - 50;

        if (nuevoY < 50) nuevoY = 50;
        if (nuevoY >= scene()->height() - pixmap().height() - 150) nuevoY = scene()->height() - pixmap().height() - 200;
    }

    setPos(nuevoX, nuevoY);
}



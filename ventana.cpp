#include "ventana.h"

Ventana::Ventana() : musicaFondo(new QMediaPlayer(this))
{

    fondo = new QLabel(this);
    QPixmap pixmap(":/Menu.jpg");
    fondo->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding));

    botonRegistro = new QPushButton("Registro", this);
    botonIniciarSesion = new QPushButton("Iniciar Sesión", this);

    botonIniciarSesion->setGeometry(600, 300, 100, 50);
    botonRegistro->setGeometry(500, 300, 100, 50);

    connect(botonIniciarSesion, &QPushButton::clicked, this, &Ventana::onBotonIniciarSesionClicked);
    connect(botonRegistro, &QPushButton::clicked, this, &Ventana::onBotonRegistroClicked);

    QAudioOutput *audioOutput = new QAudioOutput(this);
    musicaFondo->setAudioOutput(audioOutput);
    musicaFondo->setSource(QUrl("qrc:/musica.mp3"));
    musicaFondo->setLoops(QMediaPlayer::Once);
    musicaFondo->play();
}

void Ventana::resizeEvent(QResizeEvent *event)
{
    fondo->setGeometry(this->rect());
    fondo->setPixmap(QPixmap(":/Menu.jpg").scaled(this->size(), Qt::KeepAspectRatioByExpanding));
}

void Ventana::onBotonIniciarSesionClicked()
{
    LoginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted)
    {
        musicaFondo->stop();
        NivelWindow *nivel = new NivelWindow();
        nivel->show();
        this->close();
    }
}

void Ventana::onBotonRegistroClicked()
{
    RegisterDialog registerDialog(this);
    registerDialog.exec();
}


#include "ventana.h"
#include "logindialog.h"
#include "registerdialog.h"
#include "nivel.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QAudioOutput>

Ventana::Ventana(QWidget *parent)
    : QMainWindow(parent), musicaFondo(new QMediaPlayer(this))
{
    fondo = new QLabel(this);
    fondo->setScaledContents(true);
    fondo->setGeometry(this->rect());
    QPixmap pixmap(":/Menu.jpg");
    fondo->setPixmap(pixmap.scaled(this->size(), Qt::KeepAspectRatioByExpanding));

    botonRegistro = new QPushButton("Registro", this);
    botonIniciarSesion = new QPushButton("Iniciar Sesión", this);

    botonIniciarSesion->setGeometry(600, 300, 100, 50);
    botonIniciarSesion->setStyleSheet("background-color: #FF8C00; color: white; font-weight: bold;");
    botonRegistro->setGeometry(500, 300, 100, 50);
    botonRegistro->setStyleSheet("background-color: #FF8C00; color: white; font-weight: bold;");

    connect(botonIniciarSesion, &QPushButton::clicked, this, &Ventana::onBotonIniciarSesionClicked);
    connect(botonRegistro, &QPushButton::clicked, this, &Ventana::onBotonRegistroClicked);

    QAudioOutput *audioOutput = new QAudioOutput(this);
    musicaFondo->setAudioOutput(audioOutput);
    musicaFondo->setSource(QUrl("qrc:/musica.mp3"));
    musicaFondo->setLoops(QMediaPlayer::Infinite);
    musicaFondo->play();
}

Ventana::~Ventana()
{
    delete musicaFondo;
}

void Ventana::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    fondo->setGeometry(this->rect());
    fondo->setPixmap(QPixmap(":/Menu.jpg").scaled(this->size(), Qt::KeepAspectRatioByExpanding));
}

void Ventana::onBotonIniciarSesionClicked()
{
    LoginDialog loginDialog(this);
    if (loginDialog.exec() == QDialog::Accepted)
    {
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


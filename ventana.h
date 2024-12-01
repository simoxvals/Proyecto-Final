#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>
#include <QMediaPlayer>
#include "registerdialog.h"
#include "logindialog.h"
#include "nivel.h"


class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    Ventana();
    void resizeEvent(QResizeEvent *event);

public slots:
    void onBotonIniciarSesionClicked();
    void onBotonRegistroClicked();

private:
    QLabel *fondo;
    QPushButton *botonRegistro;
    QPushButton *botonIniciarSesion;
    QMediaPlayer *musicaFondo;
};

#endif // VENTANA_H


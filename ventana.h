#ifndef VENTANA_H
#define VENTANA_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>
#include <QMediaPlayer>

class Ventana : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);
    ~Ventana();

protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void onBotonIniciarSesionClicked();
    void onBotonRegistroClicked();
private:
    QLabel *fondo;
    QPushButton *botonRegistro;
    QPushButton *botonIniciarSesion;
    QMediaPlayer *musicaFondo;
};

#endif // VENTANA_H


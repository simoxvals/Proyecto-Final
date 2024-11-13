#ifndef NIVEL_H
#define NIVEL_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include "ventana.h"

class NivelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit NivelWindow(QWidget *parent = nullptr);
    ~NivelWindow();

private slots:
    void jugarNivel1();
    void jugarNivel2();

private:
    QLabel *fondo;
    QPushButton *botonNivel1;
    QPushButton *botonNivel2;

};

#endif // NIVEL_H




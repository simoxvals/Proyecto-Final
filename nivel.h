#ifndef NIVEL_H
#define NIVEL_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QResizeEvent>
#include "nivel1.h"

class NivelWindow : public QMainWindow
{
    Q_OBJECT

public:
    NivelWindow();
    void resizeEvent(QResizeEvent *event);

public slots:
    void jugarNivel1();
    void jugarNivel2();

private:
    QLabel *fondo;
    QPushButton *botonNivel1;
    QPushButton *botonNivel2;

};

#endif // NIVEL_H




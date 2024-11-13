#ifndef BART_H
#define BART_H

#include "personaje.h"
#include <QObject>

class Bart : public Personaje {
    Q_OBJECT

public:
    Bart(int x, int y, QObject *parent = nullptr);
    void mover();
    void golpear();

};

#endif // BART_H

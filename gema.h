#ifndef GEMA_H
#define GEMA_H

#include "objeto.h"
#include <QTimer>

class Gema : public Objeto {
    Q_OBJECT

public:
    explicit Gema(int x, int y, QObject *parent = nullptr);

    void aparecer() override;
    void desaparecer() override;

private slots:
    void gestionarDesaparicion();

private:
    QTimer *timerDesaparicion;
};

#endif // GEMA_H







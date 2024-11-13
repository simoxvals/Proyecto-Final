#include "gema.h"

Gema::Gema(int x, int y, QObject *parent)
    : Objeto(x,y,parent){
    QPixmap pixmap(":/gema.png");

    pixmap = pixmap.scaled(30, 30, Qt::KeepAspectRatio);
    setPixmap(pixmap);
}
void Gema::aparecer() {
    setVisible(true);
}

void Gema::desaparecer() {
    setVisible(false);
}

void Gema::gestionarDesaparicion() {
    desaparecer();
    timerDesaparicion->stop();
}

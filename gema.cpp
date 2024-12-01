#include "gema.h"

Gema::Gema(int x, int y) : Objeto(x, y)
{
    QPixmap pixmap(":/gema.png");
    pixmap = pixmap.scaled(30, 30, Qt::KeepAspectRatio);
    setPixmap(pixmap);
}




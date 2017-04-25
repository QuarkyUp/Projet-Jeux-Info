#include "mur.h"

/** ---------- CONSTRUCTOR ---------- **/

Mur::Mur(qreal x, qreal y)
{
    Element::sprite = new Sprite(":/resources/resources/obstacle.png", x, y);
}

QString Mur::className()
{
    return "Mur";
}



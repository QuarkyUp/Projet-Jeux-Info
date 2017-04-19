#include "sol.h"

Sol::Sol(qreal x, qreal y)
{
    //this->sprite = new Sprite(":/resources/resources/sol.png", x, y);
    Element::sprite = new Sprite(":/resources/resources/sand.png", x, y);
}

QString Sol::className()
{
    return "Sol";
}


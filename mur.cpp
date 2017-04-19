#include "mur.h"

Mur::Mur(qreal x, qreal y)
{
    //this->sprite = new Sprite(":resources/resources/mur.png", x, y);
    Element::sprite = new Sprite(":/resources/resources/obstacle.png", x, y);
}

Sprite* Mur::getSprite()
{
    return this->sprite;
}

QString Mur::className()
{
    return "Mur";
}



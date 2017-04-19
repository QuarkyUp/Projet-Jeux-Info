#include "porte.h"

Porte::Porte(qreal x, qreal y, QString orientation)
{
    if (orientation == "haut")
        Element::sprite = new Sprite(":/resources/resources/doorUp.png", x, y);
    else if (orientation == "bas")
        Element::sprite = new Sprite(":/resources/resources/doorDown.png", x, y);
    else if (orientation == "droite")
        Element::sprite = new Sprite(":/resources/resources/doorRight.png", x, y);
    else if (orientation == "gauche")
        Element::sprite = new Sprite(":/resources/resources/doorLeft.png", x, y);
}

QString Porte::className()
{
    return "Porte";
}


#include "element.h"

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/

Element::Element(QString id, qreal x, qreal y)
{
    this->orientation = "";

    if(id == "Sol")
        this->sprite = new Sprite(":/resources/resources/sand.png", x, y);
    else if (id == "Mur")
        this->sprite = new Sprite(":/resources/resources/obstacle.png", x, y);
}

Element::Element(QString id, qreal x, qreal y, QString orientation)
{
    this->orientation = orientation;
    if(id == "Porte")
    {
        if(this->orientation == "Haut")
            this->sprite = new Sprite(":/resources/resources/doorUp.png", x, y);
        else if(this->orientation == "Bas")
            this->sprite = new Sprite(":/resources/resources/doorDown.png", x, y);
        else if(this->orientation == "Gauche")
            this->sprite = new Sprite(":/resources/resources/doorLeft.png", x, y);
        else if(this->orientation == "Droite")
            this->sprite = new Sprite(":/resources/resources/doorRight.png", x, y);
    }

}

/** ---------- METHODS ---------- **/

void Element::drawElement(QGraphicsScene* scene)
{
    scene->addItem(this->sprite->getPixmapItem());
}

/** ---------- GETTERS ---------- **/

QString Element::getId()
{
    return this->id;
}

QString Element::getOrientation()
{
    return this->orientation;
}

Sprite* Element::getSprite()
{
    return this->sprite;
}


#include "element.h"

Element::Element()
{

}

void Element::drawElement(QGraphicsScene* scene)
{
    scene->addItem(this->sprite->getPixmapItem());
}

QString Element::getStr()
{
    return this->str;
}

void Element::setStr(QString str)
{
    this->str = str;
}

Sprite* Element::getSprite()
{
    return this->sprite;
}

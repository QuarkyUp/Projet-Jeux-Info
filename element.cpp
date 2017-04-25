#include "element.h"

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/

Element::Element()
{

}

/** ---------- METHODS ---------- **/

void Element::drawElement(QGraphicsScene* scene)
{
    scene->addItem(this->sprite->getPixmapItem());
}

/** ---------- GETTERS ---------- **/

QString Element::getStr()
{
    return this->str;
}

Sprite* Element::getSprite()
{
    return this->sprite;
}

/** ---------- SETTERS ---------- **/

void Element::setStr(QString str)
{
    this->str = str;
}

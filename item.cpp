#include "item.h"

Item::Item(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    this->scene = scene;
    itemSprite = new Sprite(imagePath, coordX, coordY);
    drawItem(scene);
}

void Item::drawItem(QGraphicsScene* scene)
{
   scene->addItem(itemSprite->getPixmapItem());
}

Sprite* Item::getSprite()
{
    return this->itemSprite;
}

qreal Item::getXpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().x();
}

qreal Item::getYpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().y();
}

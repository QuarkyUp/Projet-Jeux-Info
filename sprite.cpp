#include "sprite.h"
Sprite::Sprite(QString path, qreal x, qreal y)
{
    this->path = path;
    this->coordX = x;
    this->coordY = y;

    this->pixmap = new QPixmap(this->path);
    this->pixmapItem = new QGraphicsPixmapItem(*(this->pixmap));
    this->pixmapItem->setOffset(this->coordX, this->coordY);
    this->pixmapItem->setFlag(QGraphicsItem::ItemIsFocusable);
    this->pixmapItem->setFocus();
}

QPixmap* Sprite::getPixmap()
{
    return this->pixmap;
}

QGraphicsPixmapItem* Sprite::getPixmapItem()
{
    return this->pixmapItem;
}

qreal Sprite::getCoordX()
{
    return this->coordX;
}

qreal Sprite::getCoordY()
{
    return this->coordY;
}

void Sprite::setCoordX(qreal newCoordX)
{
    this->coordX = newCoordX;
}

void Sprite::setCoordY(qreal newCoordY)
{
    this->coordY = newCoordY;
}






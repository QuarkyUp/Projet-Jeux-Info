#include "sprite.h"

Sprite::Sprite(QString path, qreal x, qreal y)
{
    this->pixmap = new QPixmap(path);
    this->pixmapItem = new QGraphicsPixmapItem(*(this->pixmap));
    this->pixmapItem->setOffset(x, y);
}

QPixmap* Sprite::getPixmap()
{
    return this->pixmap;
}

QGraphicsPixmapItem* Sprite::getPixmapItem()
{
    return this->pixmapItem;
}






#include "sprite.h"
Sprite::Sprite(QString path, qreal x, qreal y)
{
    this->path = path;

    this->pixmap = new QPixmap(this->path);
    this->pixmapItem = new QGraphicsPixmapItem(*(this->pixmap));
    this->pixmapItem->setOffset(x, y);
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






#ifndef SPRITE_H
#define SPRITE_H

#include <QGraphicsPixmapItem>

class Sprite
{
public:
    /** CONSTRUCTOR **/
    Sprite(QString, qreal, qreal);

    /** METHODS **/
    QPixmap* getPixmap();
    QGraphicsPixmapItem* getPixmapItem();

private:
    QGraphicsPixmapItem* pixmapItem;
    QPixmap* pixmap;
};

#endif // SPRITE_H

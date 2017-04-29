#ifndef SPRITE_H
#define SPRITE_H

#include <QGraphicsPixmapItem>

class Sprite
{
public:
    /** CONSTRUCTOR **/
    Sprite(QString, qreal, qreal);


    QPixmap* getPixmap();
    QGraphicsPixmapItem* getPixmapItem();


private:
    QGraphicsPixmapItem* pixmapItem;
    QString path;
    QPixmap* pixmap;
};

#endif // SPRITE_H

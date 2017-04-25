#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QPixmap>
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

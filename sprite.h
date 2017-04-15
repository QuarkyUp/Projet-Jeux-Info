#ifndef SPRITE_H
#define SPRITE_H

#include <QString>
#include <QPixmap>
#include <QGraphicsPixmapItem>

class Sprite
{
public:
    Sprite(QString, qreal, qreal);
    QPixmap* getPixmap();
    QGraphicsPixmapItem* getPixmapItem();

    QGraphicsPixmapItem* pixmapItem;

private:
    QString path;
    QPixmap* pixmap;
};

#endif // SPRITE_H

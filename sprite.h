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

    /** UTILITE DES GETTERS/SETTERS ?? **/
    qreal getCoordX();
    qreal getCoordY();
    void setCoordX(qreal newCoordX);
    void setCoordY(qreal newCoordY);

    QGraphicsPixmapItem* pixmapItem;

private:
    QString path;
    QPixmap* pixmap;

    /** ?? **/
    qreal coordX;
    qreal coordY;
};

#endif // SPRITE_H

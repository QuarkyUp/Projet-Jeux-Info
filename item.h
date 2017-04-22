#ifndef ITEM_H
#define ITEM_H

#include "element.h"
#include "sprite.h"

class Item : public Element
{
public:
    Item(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene *scene);
    Sprite* getSprite();


    qreal getXpos();
    qreal getYpos();
    QGraphicsScene* scene;
private:
    void drawItem(QGraphicsScene* scene);


    Sprite* itemSprite;
};

#endif // ITEM_H

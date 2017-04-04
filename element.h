#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsScene>
#include "sprite.h"

class Element
{
public:
    Element();
    void drawElement(QGraphicsScene* scene);

protected:
    Sprite* sprite;

};

#endif // ELEMENT_H

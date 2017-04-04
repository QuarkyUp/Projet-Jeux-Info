#ifndef PORTE_H
#define PORTE_H

#include "element.h"
#include "sprite.h"

class Porte : public Element
{
public:
    Porte(qreal x, qreal y);
    void drawPorte(QGraphicsScene* scene);

private:
    Sprite* sprite;
};

#endif // PORTE_H

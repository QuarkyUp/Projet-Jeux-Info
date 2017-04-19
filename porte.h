#ifndef PORTE_H
#define PORTE_H

#include "element.h"
#include "sprite.h"

class Porte : public Element
{
public:
    Porte(qreal x, qreal y, QString orientation);
    void drawPorte(QGraphicsScene* scene);

    QString className();
private:
    Sprite* sprite;
};

#endif // PORTE_H

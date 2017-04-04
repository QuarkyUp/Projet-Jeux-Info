#ifndef SOL_H
#define SOL_H

#include "element.h"
//#include "sprite.h"

class Sol : public Element
{
public:
    Sol(qreal x, qreal y);

    void drawSol(QGraphicsScene* scene);

private:
    Sprite* sprite;
};

#endif // SOL_H

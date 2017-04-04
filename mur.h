#ifndef MUR_H
#define MUR_H

#include "element.h"
#include "sprite.h"

class Mur : public Element
{
public:
    /** CONSTRUCTOR **/
    Mur(qreal, qreal);

    /** GETTER **/
    Sprite* getSprite();

    void drawMur(QGraphicsScene* scene);

private:
    Sprite* sprite;
};

#endif // MUR_H

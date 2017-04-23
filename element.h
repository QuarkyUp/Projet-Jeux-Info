#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsScene>
#include "sprite.h"

class Element
{
public:
    Element();
    void drawElement(QGraphicsScene* scene);
    QString getStr();
    void setStr(QString str);
    Sprite* getSprite();

protected:
    Sprite* sprite;
    QString str;

};

#endif // ELEMENT_H

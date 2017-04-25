#ifndef ELEMENT_H
#define ELEMENT_H
#include <QGraphicsScene>
#include "sprite.h"

class Element
{
public:
    /** CONSTRUCTOR **/
    Element();

    /** METHODS **/
    void drawElement(QGraphicsScene* scene);

    /** GETTERS **/
    QString getStr();
    Sprite* getSprite();

    /** SETTERS **/
    void setStr(QString str);

protected:
    Sprite* sprite;
    QString str;

};

#endif // ELEMENT_H

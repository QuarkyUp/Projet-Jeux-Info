#ifndef ELEMENT_H
#define ELEMENT_H
#include "sprite.h"

class Element
{
public:
    /** CONSTRUCTOR **/
    Element(QString, qreal, qreal);
    Element(QString, qreal, qreal, QString);

    /** METHODS **/
    void drawElement(QGraphicsScene* scene);

    /** GETTERS **/
    QString getId();
    QString getOrientation();
    Sprite* getSprite();

protected:
    Sprite* sprite;
    QString id;
    QString orientation;

};

#endif // ELEMENT_H

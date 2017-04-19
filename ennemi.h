#ifndef ENNEMI_H
#define ENNEMI_H
#include <QGraphicsScene>
#include "sprite.h"

class Ennemi
{
public:
    Ennemi(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
    qreal getXpos();
    qreal getYpos();
    Sprite* getSprite();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

private:
    void drawEnnemi(QGraphicsScene* scene);

    QGraphicsScene* scene;
    Sprite* EnnemiSprite;
};

#endif // ENNEMI_H

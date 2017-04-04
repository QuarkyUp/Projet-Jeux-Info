#include "ennemi.h"

Ennemi* Ennemi::EnnemiInstance;

Ennemi::Ennemi(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    EnnemiSprite = new Sprite(imagePath, coordX, coordY);
    drawEnnemi(scene);
}

Ennemi* Ennemi::newEnnemi(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    if (Ennemi::EnnemiInstance == NULL)
        Ennemi::EnnemiInstance = new Ennemi(imagePath, coordX, coordY, scene);
    return Ennemi::EnnemiInstance;
}

void Ennemi::drawEnnemi(QGraphicsScene* scene)
{
   scene->addItem(EnnemiSprite->getPixmapItem());
}

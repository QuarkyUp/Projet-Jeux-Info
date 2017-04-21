#include "ennemi.h"

Ennemi::Ennemi(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    this->scene = scene;
    EnnemiSprite = new Sprite(imagePath, coordX, coordY);
    drawEnnemi(scene);
}

void Ennemi::drawEnnemi(QGraphicsScene* scene)
{
   scene->addItem(EnnemiSprite->getPixmapItem());
}

Sprite* Ennemi::getSprite()
{
    return this->EnnemiSprite;
}

qreal Ennemi::getXpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().x();
}

qreal Ennemi::getYpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().y();
}

void Ennemi::moveUp()
{
    this->getSprite()->getPixmapItem()->sceneBoundingRect().moveTo(this->getXpos(), this->getYpos()-10);
}

void Ennemi::moveDown()
{
    this->getSprite()->getPixmapItem()->setPos(this->getXpos(), this->getYpos()+10);
}

void Ennemi::moveLeft()
{
    this->getSprite()->getPixmapItem()->setPos(this->getXpos()-10, this->getYpos());
}

void Ennemi::moveRight()
{
    this->getSprite()->getPixmapItem()->setPos(this->getXpos()+10, this->getYpos());
}

#include "player.h"

Player* Player::playerInstance;

Player::Player(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    this->scene = scene;
    playerSprite = new Sprite(imagePath, coordX, coordY);
    drawPlayer(scene);
    this->current_position = new QPoint(this->getSprite()->getPixmapItem()->sceneBoundingRect().x(), this->getSprite()->getPixmapItem()->sceneBoundingRect().y());}

Player* Player::newPlayer(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    if (Player::playerInstance == NULL)
        Player::playerInstance = new Player(imagePath, coordX, coordY, scene);
    return Player::playerInstance;
}

void Player::drawPlayer(QGraphicsScene* scene)
{
   scene->addItem(this->playerSprite->getPixmapItem());
}

Sprite* Player::getSprite()
{
    return this->playerSprite;

}

qreal Player::getXpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().x();
}

qreal Player::getYpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().y();
}

void Player::moveUp(Map* map)
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()-5);
    if (this->isCollidingWith(map))
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
}

void Player::moveDown(Map* map)
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()+5);
    if (this->isCollidingWith(map))
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
}

void Player::moveLeft(Map* map)
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()-5, this->getYpos());
    if (this->isCollidingWith(map))
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
}

void Player::moveRight(Map* map)
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+5, this->getYpos());
    if (this->isCollidingWith(map))
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
}

QPoint* Player::getCurrentPos()
{
    return this->current_position;
}

bool Player::isCollidingWith(Map* map)
{
    for (int i = 0; i < map->getBackground()->size(); ++i)
    {
        for (int j =0; j < map->getBackground()->at(i)->size(); ++j)
        {
            if (map->getBackground()->at(i)->at(j)->getId() == "Mur" ||
                map->getBackground()->at(i)->at(j)->getId() == "Porte")
            {
                if (this->getSprite()->getPixmapItem()->collidesWithItem(map->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem()))
                    return true;
            }
        }
    }
    return false;
}

void Player::updatePos()
{
    this->current_position->setX(this->getXpos());
    this->current_position->setY(this->getYpos());
}




#include "player.h"
#include <QDebug>

Player* Player::playerInstance;

Player::Player(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    this->scene = scene;
    playerSprite = new Sprite(imagePath, coordX, coordY);
    drawPlayer(scene);
}

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
    return this->getSprite()->getPixmapItem()->x();
}

qreal Player::getYpos()
{
    return this->getSprite()->getPixmapItem()->y();
}

void Player::moveUp()
{

}

void Player::moveDown()
{

}

void Player::moveLeft()
{

}

void Player::moveRight()
{

}




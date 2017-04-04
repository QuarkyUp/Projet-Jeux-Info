#include "player.h"

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

void Player::moveRightPlayer()
{
    this->playerSprite->pixmapItem->setOffset(this->playerSprite->getCoordX() + 50, this->playerSprite->getCoordY());
}

void Player::moveLeftPlayer()
{
    this->playerSprite->pixmapItem->setOffset(this->playerSprite->getCoordX() - 50, this->playerSprite->getCoordY());
}

void Player::moveUpPlayer()
{
    this->playerSprite->pixmapItem->setOffset(this->playerSprite->getCoordX(), this->playerSprite->getCoordY() - 50);
}

void Player::moveDownPlayer()
{
    this->playerSprite->pixmapItem->setOffset(this->playerSprite->getCoordX(), this->playerSprite->getCoordY() + 50);
}



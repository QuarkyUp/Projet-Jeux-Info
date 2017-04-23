#include "player.h"
#include <QDebug>

Player* Player::playerInstance;

Player::Player(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene)
{
    this->scene = scene;
    playerSprite = new Sprite(imagePath, coordX, coordY);
    drawPlayer(scene);
    this->current_position = new QPoint();
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
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().x();
}

qreal Player::getYpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().y();
}

void Player::moveUp()
{
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()-10);

    this->getSprite()->getPixmap()->load(":/resources/resources/playerUp.png");
    this->getSprite()->getPixmapItem()->setPixmap(*this->getSprite()->getPixmap());
}

void Player::moveDown()
{
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()+10);

    this->getSprite()->getPixmap()->load(":/resources/resources/playerDown.png");
    this->getSprite()->getPixmapItem()->setPixmap(*this->getSprite()->getPixmap());
}

void Player::moveLeft()
{
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()-10, this->getYpos());

    this->getSprite()->getPixmap()->load(":/resources/resources/playerLeft.png");
    this->getSprite()->getPixmapItem()->setPixmap(*this->getSprite()->getPixmap());
}

void Player::moveRight()
{
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos() + 10, this->getYpos());


    this->getSprite()->getPixmap()->load(":/resources/resources/playerRight.png");
    this->getSprite()->getPixmapItem()->setPixmap(*this->getSprite()->getPixmap());
}

QPoint* Player::getCurrentPos()
{
    return this->current_position;
}




#include "player.h"
#include "game.h"

#include <QDebug>

Player* Player::playerInstance;

Player::Player(Scene* scene)
{
    this->scene = scene;
    playerSprite = new Sprite(":/resources/resources/donkeyUp.png", GAME_SIZE/2 - PIXEL_SIZE, 2*PIXEL_SIZE);
    this->current_position = new QPoint(this->getSprite()->getPixmapItem()->sceneBoundingRect().x(), this->getSprite()->getPixmapItem()->sceneBoundingRect().y());
    this->createLifebar();
    this->draw();
}

Player* Player::newPlayer(Scene * scene)
{
    if (Player::playerInstance == NULL)
        Player::playerInstance = new Player(scene);
    return Player::playerInstance;
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

void Player::draw()
{
    this->scene->addItem(this->getSprite()->getPixmapItem());
    this->scene->addItem(this->getLifebarGreen());
    this->scene->addItem(this->getLifebarRed());
}

QGraphicsRectItem *Player::getLifebarGreen()
{
    return this->lifebarGreen;
}

QGraphicsRectItem* Player::getLifebarRed()
{
    return this->lifebarRed;
}

void Player::moveUp()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()-5);
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
    this->updateLifebarPos();
}

void Player::moveDown()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()+5);
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
    this->updateLifebarPos();
}

void Player::moveLeft()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()-5, this->getYpos());
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
    this->updateLifebarPos();
}

void Player::moveRight()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+5, this->getYpos());
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
    this->updateLifebarPos();
}

QPoint* Player::getCurrentPos()
{
    return this->current_position;
}

bool Player::isCollidingWithMap()
{
    for (int i = 0; i < this->scene->getGame()->getCurrentMap()->getBackground()->size(); ++i)
    {
        for (int j =0; j < this->scene->getGame()->getCurrentMap()->getBackground()->at(i)->size(); ++j)
        {
            if (this->scene->getGame()->getCurrentMap()->getBackground()->at(i)->at(j)->getId() == "Mur" ||
                this->scene->getGame()->getCurrentMap()->getBackground()->at(i)->at(j)->getId() == "Porte")
            {
                if (this->getSprite()->getPixmapItem()->collidesWithItem(this->scene->getGame()->getCurrentMap()->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem()))
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
void Player::createLifebar()
{
    qreal startGreenX = this->getXpos()-8;
    qreal startGreenY = this->getYpos()-10;

    this->lifebarGreen = new QGraphicsRectItem(startGreenX, startGreenY, this->playerLife, 10);
    lifebarGreen->setBrush(*new QBrush(Qt::green));

    this->lifebarRed = new QGraphicsRectItem(startGreenX + this->playerLife, startGreenY, 50.0 - this->playerLife, 10);
    lifebarRed->setBrush(*new QBrush(Qt::red));
}

void Player::updateLifebarPos()
{
    qreal startGreenX = this->getXpos()-8;
    qreal startGreenY = this->getYpos()-10;

    //update green
    this->lifebarGreen->setRect(startGreenX, startGreenY, this->playerLife, 10);

    //update red
    this->lifebarRed->setRect(startGreenX + this->playerLife, startGreenY, 50.0 - this->playerLife, 10);

    if (this->playerLife < 0)
        exit(0);

}

void Player::reduceLife(float reduceLife)
{
    this->updateLifebarPos();
    this->playerLife -= reduceLife;
}

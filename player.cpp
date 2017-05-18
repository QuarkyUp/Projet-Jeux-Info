#include "player.h"
#include "game.h"

#include <QDebug>

Player* Player::playerInstance;

Player::Player(Scene* scene)
{
    this->scene = scene;
    playerSprite = new Sprite(":/resources/resources/donkeyUp.png", 600, 200);
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
    this->scene->addItem(this->getLifebar());
}

QGraphicsRectItem *Player::getLifebar()
{
    return this->lifebar;
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
    for (int i = 0; i < this->scene->getGame()->getMap()->getBackground()->size(); ++i)
    {
        for (int j =0; j < this->scene->getGame()->getMap()->getBackground()->at(i)->size(); ++j)
        {
            if (this->scene->getGame()->getMap()->getBackground()->at(i)->at(j)->getId() == "Mur" ||
                this->scene->getGame()->getMap()->getBackground()->at(i)->at(j)->getId() == "Porte")
            {
                if (this->getSprite()->getPixmapItem()->collidesWithItem(this->scene->getGame()->getMap()->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem()))
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
    this->lifebar = new QGraphicsRectItem(this->getXpos()-8, this->getYpos()-10, 2*this->playerLife, 10);
    lifebar->setBrush(*new QBrush(Qt::red));
}

void Player::updateLifebarPos()
{
    /*
    if(this->playerLife <= 0)
        this->lifebar->setRect(this->getXpos()-8, this->getYpos()-10, 0, 10);
    else
    */
        qDebug() << this->playerLife;
        this->lifebar->setRect(this->getXpos()-8, this->getYpos()-10, 2*this->playerLife, 10);

    //this->lifebar->setRect(this->getXpos()-8, this->getYpos()-10, 50, 10);
}

void Player::reduceLife(float reduceLife)
{
    this->updateLifebarPos();
    this->playerLife -= reduceLife;
}

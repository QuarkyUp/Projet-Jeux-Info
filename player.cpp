#include "player.h"
#include "game.h"

Player* Player::playerInstance;

Player::Player(Scene* scene)
{
    this->scene = scene;
    playerSprite = new Sprite(":/resources/resources/donkeyUp.png", 600, 200);
    this->current_position = new QPoint(this->getSprite()->getPixmapItem()->sceneBoundingRect().x(), this->getSprite()->getPixmapItem()->sceneBoundingRect().y());
    this->createLifebar();
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
}

void Player::moveDown()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()+5);
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
}

void Player::moveLeft()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()-5, this->getYpos());
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
}

void Player::moveRight()
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+5, this->getYpos());
    if (this->isCollidingWithMap())
        this->getSprite()->getPixmapItem()->setOffset(this->getCurrentPos()->x(), this->getCurrentPos()->y());
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
    this->lifebar->setRect(this->getXpos()-15, this->getYpos(), 10, 50);
}

void Player::createLifebar()
{
    this->lifebar = new QGraphicsRectItem(this->getXpos()-15, this->getYpos(), 10, 50);
    lifebar->setBrush(*new QBrush(Qt::red));
}





#include "ennemyintel.h"
#include <math.h>


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player)
{
    this->ennemi = ennemi;
    this->player = player;
}

void EnnemyIntel::run()
{
    while(true){
    QThread::sleep(1);
    //ennemi->getSprite()->getPixmapItem()->setPos(ennemi->getXpos()+100, ennemi->getYpos());

    moveTowardsPlayer();
    }
}

void EnnemyIntel::moveTowardsPlayer()
{
    double dx = this->player->getSprite()->getPixmapItem()->pos().x() - this->ennemi->getSprite()->getPixmapItem()->pos().x();
    double dy = this->player->getSprite()->getPixmapItem()->pos().y() - this->ennemi->getSprite()->getPixmapItem()->pos().y();

    double dist = sqrt(dx*dx + dy*dy);
    while(dist > 20)
    {
        double moveX = (dx/dist)*5;
        double moveY = (dy/dist)*5;
        ennemi->getSprite()->getPixmapItem()->setPos(ennemi->getXpos()+moveX, ennemi->getYpos());
        ennemi->getSprite()->getPixmapItem()->setPos(ennemi->getXpos()+moveX, ennemi->getYpos()+moveY);
    }
}

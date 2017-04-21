#include "ennemyintel.h"
#include <math.h>


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player)
{
    this->ennemi = ennemi;
    this->player = player;
}

void EnnemyIntel::run()
{
        //ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos()+10, ennemi->getYpos());
        moveTowardsPlayer();
}

// Mauvais Référentiel
void EnnemyIntel::moveTowardsPlayer()
{
    double dx = this->player->getXpos() - this->ennemi->getXpos();
    double dy = this->player->getYpos() - this->ennemi->getYpos();

    double dist = sqrt(dx*dx + dy*dy);
    //qDebug() << dist;
    if(dist > 20)
    {
        double moveX = (dx/dist)*1;
        double moveY = (dy/dist)*1;
        ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos()+moveX, ennemi->getYpos());
        ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos()+moveX, ennemi->getYpos()+moveY);
    }
}

#include "ennemyintel.h"
#include <math.h>


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player, QVector<Ennemi*>* ennemiVector)
{
    this->ennemi = ennemi;
    this->player = player;
    this->ennemiVector = ennemiVector;
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
    double moveX = (dx/dist)*1;
    double moveY = (dy/dist)*1;

    bool isMoveOkay = true;
    QList<QGraphicsItem *> list = this->ennemi->getSprite()->getPixmapItem()->collidingItems();
    list.removeOne(this->ennemi->getSprite()->getPixmapItem());

    for (int i = 0; i < list.length(); i++){
        if(this->ennemi->getSprite()->getPixmapItem()->collidesWithItem(list.at(i)))
        {
            isMoveOkay = false;

        }
    }

    if((dist > 60))
    {
        ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos()+moveX, ennemi->getYpos());
        ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos(), ennemi->getYpos()+moveY);
    }
}

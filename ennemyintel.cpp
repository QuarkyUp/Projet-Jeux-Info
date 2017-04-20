#include "ennemyintel.h"
#include <math.h>


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player)
{
    this->ennemi = ennemi;
    this->player = player;
}

void EnnemyIntel::run()
{
    // ------------------------------------------------------------------
    // Les déplacements fonctionnent sans Timer et sans boucle while
    // NEED BIG FIX
    // ------------------------------------------------------------------

    //while(true)
    //{
        /*
        qDebug() << "before start";
        timer.start(1000);
        qDebug() << "between start and while";
        while (timer.remainingTime() > 0);
        qDebug() << "after while";
        */

        //qDebug() << ennemi->getXpos();
        ennemi->getSprite()->getPixmapItem()->setPos(ennemi->getXpos()+500, ennemi->getYpos());
        //ennemi->getSprite()->getPixmapItem()->setPos(ennemi->getXpos()+250, ennemi->getYpos());
        //qDebug() << ennemi->getXpos();


        //moveTowardsPlayer();
    //}


}

// Mauvais Référentiel
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

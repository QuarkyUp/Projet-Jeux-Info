#include "ennemyintel.h"


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player)
{
    this->ennemi = ennemi;
    this->player = player;
}

void EnnemyIntel::run()
{
    qDebug() << player->getSprite()->getPixmapItem()->pos();
    QThread::sleep(1);
    player->getSprite()->getPixmapItem()->setPos(ennemi->getXpos()+100, ennemi->getYpos());
    qDebug() << player->getSprite()->getPixmapItem()->pos();
}

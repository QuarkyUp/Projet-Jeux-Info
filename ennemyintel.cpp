#include "ennemyintel.h"


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player)
{
    this->ennemi = ennemi;
    this->player = player;
}

void EnnemyIntel::run()
{
    while (1){
        QThread::sleep(1);
        ennemi->moveRight();
        qDebug() << ennemi->getSprite()->getPixmapItem()->pos();
    }


}

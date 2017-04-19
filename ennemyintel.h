#ifndef ENNEMYINTEL_H
#define ENNEMYINTEL_H

#include <QThread>
#include "ennemi.h"
#include "player.h"

class EnnemyIntel : public QThread
{
public:
    EnnemyIntel(Ennemi* ennemi, Player* player);

private:
    void run();

    Ennemi* ennemi;
    Player* player;
};

#endif // ENNEMYINTEL_H

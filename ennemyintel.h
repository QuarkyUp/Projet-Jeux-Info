#ifndef ENNEMYINTEL_H
#define ENNEMYINTEL_H

#include <QThread>
#include <QTimer>
#include "ennemi.h"
#include "player.h"

class EnnemyIntel : public QThread
{
public:
    EnnemyIntel(Ennemi* ennemi, Player* player);
    void moveTowardsPlayer();

private:
    void run();

    Ennemi* ennemi;
    Player* player;

    QTimer timer;
};

#endif // ENNEMYINTEL_H

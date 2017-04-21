#ifndef ENNEMYINTEL_H
#define ENNEMYINTEL_H

#include <QTimer>
#include <QObject>
#include "ennemi.h"
#include "player.h"

class EnnemyIntel: public QObject
{
    Q_OBJECT
public:
    EnnemyIntel(Ennemi* ennemi, Player* player);
    void moveTowardsPlayer();


public slots:
    void run();

private:


    Ennemi* ennemi;
    Player* player;
};

#endif // ENNEMYINTEL_H

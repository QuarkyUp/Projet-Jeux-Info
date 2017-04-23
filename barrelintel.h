#ifndef BARRELINTEL_H
#define BARRELINTEL_H
#include "item.h"
#include "player.h"
#include <cmath>

class BarrelIntel: public QObject
{
    Q_OBJECT
public:
    BarrelIntel(Item* barrel, Player* player, qreal mousePosX, qreal mousePosY);

    void changeRotation();
public slots:
    void run();

private:
    Item* barrel;
    Player* player;
    qreal mousePosX;
    qreal mousePosY;
    void moveTowardsMouse();
    bool rotation = true;
};

#endif // BARRELINTEL_H

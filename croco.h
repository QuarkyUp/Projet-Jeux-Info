#ifndef CROCO_H
#define CROCO_H

#include <QGraphicsScene>
#include <QTimer>
#include <cmath>

#include "sprite.h"
#include "player.h"

class Croco : public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR / DESTRUCTOR **/
    Croco(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene, Player* player);
    ~Croco();

    /** METHODS **/
    void drawCroco();
    void removeCroco();
    void changeRotation();
    void moveTowardsPlayer();

    /** GETTERS **/
    qreal getXpos();
    qreal getYpos();
    Sprite* getSprite();
    QTimer* getTimer();

public slots:
    void run();

private:
    Sprite* crocoSprite;
    Player* player;
    QGraphicsScene* scene;
    QTimer* timer;
};

#endif // CROCO_H

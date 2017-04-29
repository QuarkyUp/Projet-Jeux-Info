#ifndef CROCO_H
#define CROCO_H

#include <QTimer>
#include <cmath>
#include "scene.h"
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
    void updatePos();
    void move(double, double);

    bool isCollidingWith(Map*);

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
    QPoint* current_position;
};

#endif // CROCO_H

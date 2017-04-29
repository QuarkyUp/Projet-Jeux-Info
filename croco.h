#ifndef CROCO_H
#define CROCO_H

#include <QObject>
#include <QTimer>
#include "scene.h"
#include "player.h"


class Croco : public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR / DESTRUCTOR **/
    Croco(qreal coordX, qreal coordY, Scene* scene, Player* player);
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
    Scene* scene;
    QTimer* timer;
    QPoint* current_position;
};

#endif // CROCO_H

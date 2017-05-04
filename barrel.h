#ifndef BARREL_H
#define BARREL_H

#include <QObject>
#include "scene.h"
#include "player.h"
#include "game.h"


class Barrel : public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR / DESTRUCTOR **/
    Barrel(QPointF* mousePos, Scene* scene);
    ~Barrel();

    /** METHODS **/
    void drawBarrel();
    void removeBarrel();
    void changeRotation();
    void moveTowardsMouse();

    bool isCollidingWithMap();
    bool isCollidingWithCroco();

    /** GETTERS **/
    qreal getXpos();
    qreal getYpos();
    Sprite* getSprite();

public slots:
    void run();

private:
    Sprite* sprite;
    Scene* scene;
    Player* player;
    QPointF* mousePos;
    QTimer* timer;
    bool rotation = true;

};

#endif // BARREL_H

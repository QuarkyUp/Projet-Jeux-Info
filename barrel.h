#ifndef BARREL_H
#define BARREL_H

#include "sprite.h"
#include "player.h"
#include "scene.h"
#include <QPointF>
#include <cmath>
#include <QTimer>

class Barrel : public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR / DESTRUCTOR **/
    Barrel(QString imagePath, qreal coordX, qreal coordY, QPointF mousePos, Scene* scene, Player* player);
    ~Barrel();

    /** METHODS **/
    void drawBarrel();
    void removeBarrel();
    void changeRotation();
    void moveTowardsMouse();

    bool isCollidingWith(Map*);

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
    QPointF mousePos;
    QTimer* timer;
    bool rotation = true;

};

#endif // BARREL_H

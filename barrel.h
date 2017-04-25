#ifndef BARREL_H
#define BARREL_H

#include "sprite.h"
#include "player.h"
#include <QGraphicsScene>
#include <QPointF>
#include <cmath>
#include <QTimer>

class Barrel : public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR / DESTRUCTOR **/
    Barrel(QString imagePath, qreal coordX, qreal coordY, QPointF mousePos, QGraphicsScene* scene, Player* player);
    ~Barrel();

    /** METHODS **/
    void drawBarrel();
    void removeBarrel();
    void changeRotation();
    void moveTowardsMouse();

    /** GETTERS **/
    qreal getXpos();
    qreal getYpos();
    Sprite* getSprite();

public slots:
    void run();

private:
    Sprite* sprite;
    QGraphicsScene* scene;
    Player* player;
    QPointF mousePos;
    QTimer* timer;
    bool rotation = true;

};

#endif // BARREL_H

#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>
#include "personnage.h"
#include "sprite.h"

class Player : public Personnage
{
public:
    static Player* newPlayer(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
    void moveRightPlayer();
    void moveLeftPlayer();
    void moveUpPlayer();
    void moveDownPlayer();
private:
    Player(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
    void drawPlayer(QGraphicsScene* scene);

    QGraphicsScene* scene;
    static Player* playerInstance;
    Sprite* playerSprite;
};

#endif // PLAYER_H

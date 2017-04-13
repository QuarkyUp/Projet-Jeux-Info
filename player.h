#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>

#include "sprite.h"

class Player
{
public:
    /** CONSTRUCTOR **/
    static Player* newPlayer(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);

    /** METHODS **/

      qreal getXpos();
      qreal getYpos();

      void moveUp();
      void moveDown();
      void moveLeft();
      void moveRight();
    /** GETTERS **/
    Sprite* getSprite();

private:
    Player(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
    void drawPlayer(QGraphicsScene* scene);

    QGraphicsScene* scene;
    static Player* playerInstance;
    Sprite* playerSprite;
};

#endif // PLAYER_H

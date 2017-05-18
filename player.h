#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "scene.h"
#include <QBrush>

class Player
{
public:
    /** CONSTRUCTOR **/
    static Player* newPlayer(Scene*);

    /** METHODS **/

      qreal getXpos();
      qreal getYpos();

      void draw();
      void moveUp();
      void moveDown();
      void moveLeft();
      void moveRight();
      void updatePos();
      void createLifebar();
      void updateLifebarPos();
      void reduceLife(float reduceLife);


      bool isCollidingWithMap();

    /** GETTERS **/
    Sprite* getSprite();
    QPoint* getCurrentPos();
    QGraphicsRectItem* getLifebar();

private:
    Player(Scene* scene);

    Scene* scene;
    static Player* playerInstance;
    Sprite* playerSprite;
    QPoint* current_position;
    QGraphicsRectItem* lifebar;
    float playerLife = 25.0;
};

#endif // PLAYER_H

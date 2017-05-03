#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include <QBrush>
#include <QDebug>

class Player
{
public:
    /** CONSTRUCTOR **/
    static Player* newPlayer();

    /** METHODS **/

      qreal getXpos();
      qreal getYpos();

      void moveUp(Map*);
      void moveDown(Map*);
      void moveLeft(Map*);
      void moveRight(Map*);
      void updatePos();
      void createLifebar();
//      void drawPlayer(Scene* scene);


      bool isCollidingWith(Map*);

    /** GETTERS **/
    Sprite* getSprite();
    QPoint* getCurrentPos();
    QGraphicsRectItem* getLifebar();

private:
    Player();


    static Player* playerInstance;
    Sprite* playerSprite;
    QPoint* current_position;
    QGraphicsRectItem* lifebar;
};

#endif // PLAYER_H

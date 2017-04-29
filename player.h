#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

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
//      void drawPlayer(Scene* scene);


      bool isCollidingWith(Map*);

    /** GETTERS **/
    Sprite* getSprite();
    QPoint* getCurrentPos();
private:
    Player();


    static Player* playerInstance;
    Sprite* playerSprite;
    QPoint* current_position;
};

#endif // PLAYER_H

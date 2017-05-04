#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"
#include "scene.h"

class Player
{
public:
    /** CONSTRUCTOR **/
    static Player* newPlayer(Scene*);

    /** METHODS **/

      qreal getXpos();
      qreal getYpos();

      void moveUp();
      void moveDown();
      void moveLeft();
      void moveRight();
      void updatePos();


      bool isCollidingWithMap();

    /** GETTERS **/
    Sprite* getSprite();
    QPoint* getCurrentPos();
private:
    Player(Scene* scene);

    Scene* scene;
    static Player* playerInstance;
    Sprite* playerSprite;
    QPoint* current_position;
};

#endif // PLAYER_H

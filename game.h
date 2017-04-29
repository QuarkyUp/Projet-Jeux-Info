#ifndef GAME_H
#define GAME_H

#include "map.h"
#include "player.h"

class Game: public QObject
{
public:
    /** CONSTRUCTOR **/
    Game();

    /** METHODS **/
    void generateMap(QGraphicsScene*);
    void sendKeyboardEvent(QString);
    bool collisionPlayerEnnemy();

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();

private:
    Map* map;
    Player* myPlayer;
};

#endif // GAME_H

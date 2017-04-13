#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>

#include "map.h"
#include "player.h"


class Game
{
public:
    /** CONSTRUCTOR **/
    Game();

    /** METHODS **/

    void generateMap(QGraphicsScene*);

    /** GETTER **/

private:

    Map* map;
    Player* myPlayer;
};

#endif // GAME_H

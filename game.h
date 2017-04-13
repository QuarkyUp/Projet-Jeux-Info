#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>

#include "map.h"
#include "player.h"


class Game
{
public:
    /** CONSTRUCTOR **/
    Game(QGraphicsScene*);

    /** METHODS **/

    void generateMap(QGraphicsScene*);

    void sendKeyboardEvent(QString);

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();

private:

    Map* map;
    Player* myPlayer;
};

#endif // GAME_H

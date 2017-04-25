#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QTimer>
#include <QObject>

#include "map.h"
#include "player.h"
#include "croco.h"


class Game: public QObject
{
public:
    /** CONSTRUCTOR **/
    Game();

    /** METHODS **/

    void generateMap(QGraphicsScene* scene);

    void sendKeyboardEvent(QString);

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();

private:
    Map* map;
    Player* myPlayer;
};

#endif // GAME_H

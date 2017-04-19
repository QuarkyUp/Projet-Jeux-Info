#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>

#include "map.h"
#include "player.h"
#include "ennemi.h"
#include "ennemyintel.h"


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
    QVector<Ennemi*>* ennemiVector;
    QVector<EnnemyIntel*>* ennemiIntelVector;
};

#endif // GAME_H

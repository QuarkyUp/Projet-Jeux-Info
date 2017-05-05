#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "map.h"
#include "player.h"
#include "barrel.h"


class Game: public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR **/
    Game(Scene*);
    ~Game();

    /** METHODS **/
    void start();
    void generateMap();
    void generatePlayer();

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();

private:
    Map* map;
    Player* myPlayer;
    Scene* scene;


};

#endif // GAME_H

#ifndef GAME_H
#define GAME_H

#include "scene.h"
#include "map.h"
#include "player.h"
#include "barrel.h"
#include "croco.h"

class Game: public QObject
{
private:
    Map* map;
    Player* myPlayer;
    Scene* scene;

public:
    /** CONSTRUCTOR **/
    Game(Scene*);

    /** METHODS **/
    void generateMap();
    void sendKeyboardEvent(QString);
    bool collisionPlayerEnnemy();

    void createMap();
    void drawMap();
    void drawPlayer();
    void drawEnnemy();
    void createBarrel(QPointF*);

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();


};

#endif // GAME_H

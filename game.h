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
    void generateMap();
    void generatePlayer();
    void sendKeyboardEvent(QString);
    bool collisionPlayerEnnemy();

    void createMap();
    void drawMap();
    void drawPlayer();
    void drawEnnemy();
    void createBarrel(QPointF*);
    void removeCroco(int);

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();

    /** SLOTS **/
public slots:
    void holdTheDoor();

private:
    Map* map;
    Player* myPlayer;
    Scene* scene;


};

#endif // GAME_H

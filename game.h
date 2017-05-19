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
    Map* getCurrentMap();
    Player* getPlayer();

public slots:
    void changeMap(QString);

private:
    Map* currentMap;
    QVector<Map*>* QMap;
    Player* myPlayer;
    Scene* scene;
    QPoint* currentPosInSpace;


};

#endif // GAME_H

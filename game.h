#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "map.h"

#define GAME_SIZE 31*31

class Game
{
public:
    /** CONSTRUCTOR **/
    Game();

    /** METHODS **/
    void createView();
    void generateMap();

    /** GETTER **/
    QGraphicsScene* getScene();

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Map* map;
};

#endif // GAME_H

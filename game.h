#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

#include "map.h"
#include "player.h"

#define GAME_SIZE 31*31

class Game : public QWidget
{
public:
    /** CONSTRUCTOR **/
    Game();

    /** METHODS **/
    void createView();
    void generateMap();
    void keyPressEvent(QKeyEvent*);

    /** GETTER **/
    QGraphicsScene* getScene();

private:
    QGraphicsScene* scene;
    QGraphicsView* view;
    Map* map;
    Player* myPlayer;
};

#endif // GAME_H

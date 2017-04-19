#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"

#define GAME_SIZE 31*31

class Scene : public QGraphicsScene
{
public:
    /** CONSTRUCTOR **/
    Scene();

    /** METHODS **/
    void start();
    void keyPressEvent(QKeyEvent* event);
    void createView();
    void createGame();

    /** GETTER **/
    QGraphicsView* getView();
    Game* getGame();

private:
    QGraphicsView* view;
    Game* game;
};

#endif // SCENE_H

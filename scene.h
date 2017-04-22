#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
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

    void mouseMoveEvent  (QGraphicsSceneMouseEvent * event );

private:
    QGraphicsView* view;
    Game* game;
    qreal lastMousePosX;
    qreal lastMousePosY;
};

#endif // SCENE_H

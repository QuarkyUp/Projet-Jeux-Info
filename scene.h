#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include "game.h"
#include <QTimer>
#include "barrel.h"

#define GAME_SIZE 31*31

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /** CONSTRUCTOR **/
    Scene();

    /** METHODS **/
    void start();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void createView();
    void createGame();
    bool collisonMur();
    void updateOrientation();

    /** GETTER **/
    QGraphicsView* getView();
    Game* getGame();

    void mouseMoveEvent  (QGraphicsSceneMouseEvent * event );

    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

public slots:
    void updateKey();

private:
    QGraphicsView* view;
    Game* game;
    qreal lastMousePosX;
    qreal lastMousePosY;
    QVector<bool>* mvt;
};

#endif // SCENE_H

#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include "game.h"

#define GAME_SIZE 31*31

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /** CONSTRUCTOR **/
    Scene();
    ~Scene();

    /** METHODS **/
    void start();
    void createView();
    void createGame();
    void updateOrientation();
    bool collisonMur();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mouseMoveEvent  (QGraphicsSceneMouseEvent * event );
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);

    /** GETTER **/
    QGraphicsView* getView();
    Game* getGame();

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

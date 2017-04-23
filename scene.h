#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include "game.h"
#include "item.h"
#include "barrelintel.h"
#include <QTimer>

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
    bool collison();

    /** GETTER **/
    QGraphicsView* getView();
    Game* getGame();

    void mouseMoveEvent  (QGraphicsSceneMouseEvent * event );

    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
private:
    QGraphicsView* view;
    Game* game;
    qreal lastMousePosX;
    qreal lastMousePosY;

    QVector<BarrelIntel*>* barrelIntelVector;
    QVector<Item*>* barrelVector;
    QVector<QTimer*>* barrelTimer;
};

#endif // SCENE_H

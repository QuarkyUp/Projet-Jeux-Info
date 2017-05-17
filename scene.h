#ifndef SCENE_H
#define SCENE_H

#define GAME_SIZE 31*31

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <cmath>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>

class Game;

class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /** CONSTRUCTOR **/
    Scene();
    ~Scene();

    /** METHODS **/
    void setGame(Game*);
    void start();
    void createView();
    void createGame();
    void updateOrientation();
    bool collisonMur();
    void createMvtTimer();
    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event );
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    /** GETTER **/
    QGraphicsView* getView();
    Game* getGame();

public slots:
    void updateKey();


signals:
    void changeMapEvent(QString);

private:
    QGraphicsView* view;
    Game* game;
    qreal lastMousePosX;
    qreal lastMousePosY;
    QVector<bool>* mvt;
    QTimer* mvtTimer;
    void emitChangeMapEvent();

};

#endif // SCENE_H

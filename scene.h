#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <game.h>

#define GAME_SIZE 31*31

class Scene : public QGraphicsScene
{
public:
    Scene();
    void keyPressEvent(QKeyEvent* event);
    void createView();

private:
    QGraphicsView* view;
    Game* game;
};

#endif // SCENE_H

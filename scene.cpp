#include "scene.h"
#include <QDebug>
#include <QKeyEvent>

Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);
}

void Scene::start()
{
    this->createView();
    this->createGame();
}


void Scene::keyPressEvent(QKeyEvent* event)
{
    if (event->isAutoRepeat()){
        if (event->key() == Qt::Key_Up)
            this->game->sendKeyboardEvent("UP");
        else if (event->key() == Qt::Key_Down)
            this->game->sendKeyboardEvent("DOWN");
        else if (event->key() == Qt::Key_Left)
            this->game->sendKeyboardEvent("LEFT");
        else if (event->key() == Qt::Key_Right)
            this->game->sendKeyboardEvent("RIGHT");
    }
}


/*
void Scene::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_Left:
            this->game->sendKeyboardEvent("LEFT");
            break;
        case Qt::Key_Right:
            this->game->sendKeyboardEvent("RIGHT");
            break;
        case Qt::Key_Up:
            this->game->sendKeyboardEvent("UP");
            break;
        case Qt::Key_Down:
            this->game->sendKeyboardEvent("DOWN");
            break;
    }
}

void Scene::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        switch(event->key()) {
            case Qt::Key_Left:
                this->game->sendKeyboardEvent("LEFT");
                break;
            case Qt::Key_Right:
                this->game->sendKeyboardEvent("RIGHT");
                break;
            case Qt::Key_Up:
                this->game->sendKeyboardEvent("UP");
                break;
            case Qt::Key_Down:
                this->game->sendKeyboardEvent("DOWN");
                break;
        }
    }
}
*/

void Scene::createView()
{
    this->view = new QGraphicsView(this);

    /** OBLIGER DE FAIRE +2 PIXEL SINON LES SCROLLBARS APPARAISSENT **/
    this->view->setFixedSize(this->width()+2, this->height()+2);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
}

void Scene::createGame()
{
    this->game = new Game(this);
    this->game->generateMap(this);
}

QGraphicsView* Scene::getView()
{
    return this->view;
}

Game* Scene::getGame()
{
    return this->game;
}

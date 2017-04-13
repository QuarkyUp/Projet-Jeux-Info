#include "scene.h"
#include <QDebug>
#include <QKeyEvent>

Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);

    this->createView();
    this->createGame();

}

void Scene::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up)
        qDebug() << "UP";
    else if (event->key() == Qt::Key_Down)
        qDebug() << "DOWN";
    else if (event->key() == Qt::Key_Left)
        qDebug() << "LEFT";
    else if (event->key() == Qt::Key_Right)
        qDebug() << "RIGTH";
}

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

#include "scene.h"
#include <QDebug>
#include <QKeyEvent>

Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);
    this->game = new Game();
    this->game->generateMap(this);
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
    view->setFixedSize(this->width()+2, this->height()+2);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
}

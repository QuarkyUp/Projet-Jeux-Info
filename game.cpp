#include "game.h"

#include <QDebug>

Game::Game()
{
    this->setFocus();
    this->scene = new QGraphicsScene(0, 0, GAME_SIZE, GAME_SIZE);
    createView();
}

void Game::createView()
{
    this->view = new QGraphicsView(scene);

    /** OBLIGER DE FAIRE +2 PIXEL SINON LES SCROLLBARS APPARAISSENT **/
    view->setFixedSize(scene->width()+2, scene->height()+2);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
}

void Game::generateMap()
{
    this->map = new Map();
    map->createMap();
    map->drawMap(getScene());

    this->myPlayer = Player::newPlayer(":/resources/resources/player.png", 100, 100, scene);
}

QGraphicsScene* Game::getScene()
{
    return this->scene;
}

void Game::keyPressEvent(QKeyEvent * event)
{
    qDebug() << "Olala";
    if (event->key() == Qt::Key_Up)
        this->myPlayer->getSprite()->getPixmapItem()->setPos(this->myPlayer->getXpos(), this->myPlayer->getYpos()-50);
    if (event->key() == Qt::Key_Space)
        qDebug() << "ESPACE ESPACE ESPACE";
}




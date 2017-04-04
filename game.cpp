#include "game.h"
#include "player.h"

Game::Game()
{
    this->scene = new QGraphicsScene(0, 0, GAME_SIZE, GAME_SIZE);
    createView();

    generateMap();
    Player* myPlayer = Player::newPlayer(":/resources/resources/player.png", 100, 100, scene);
    myPlayer->moveRightPlayer();


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
}

QGraphicsScene* Game::getScene()
{
    return this->scene;
}


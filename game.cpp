#include "game.h"

#include <QDebug>

Game::Game()
{

}


void Game::generateMap(QGraphicsScene* scene)
{
    this->map = new Map();
    map->createMap();
    map->drawMap(scene);

    this->myPlayer = Player::newPlayer(":/resources/resources/player.png", 100, 100, scene);
}




#include "game.h"

#include <QDebug>

Game::Game(QGraphicsScene* scene)
{
    this->map = new Map();
    this->myPlayer = Player::newPlayer(":/resources/resources/player.png", 100, 100, scene);
}


void Game::generateMap(QGraphicsScene* scene)
{
    map->createMap();
    map->drawMap(scene);
}

Map* Game::getMap()
{
    return this->map;
}

Player* Game::getPlayer()
{
    return this->myPlayer;
}




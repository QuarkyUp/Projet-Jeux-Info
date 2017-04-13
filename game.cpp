#include "game.h"

#include <QDebug>

Game::Game(QGraphicsScene* scene)
{
    this->map = new Map();
}


void Game::generateMap(QGraphicsScene* scene)
{
    map->createMap();
    map->drawMap(scene);
    this->myPlayer = Player::newPlayer(":/resources/resources/player.png", 100, 100, scene);

}

Map* Game::getMap()
{
    return this->map;
}

Player* Game::getPlayer()
{
    return this->myPlayer;
}

void Game::sendKeyboardEvent(QString string)
{
    if (string == "UP")
        this->getPlayer()->moveUp();
    else if (string == "DOWN")
        this->getPlayer()->moveDown();
    else if (string == "LEFT")
        this->getPlayer()->moveLeft();
    else if (string == "RIGHT")
        this->getPlayer()->moveRight();
}

#include "game.h"

#include <QDebug>
#include <QThread>

Game::Game()
{
    this->map = new Map();
}


void Game::generateMap(QGraphicsScene* scene)
{
    map->createMap();
    map->drawMap(scene);
    this->myPlayer = Player::newPlayer(":/resources/resources/donkeyUp.png", 120, 600, scene);

    Croco* croco = new Croco(":/resources/resources/ennemiUp.png", 100,100, scene, this->getPlayer());
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


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
    this->myPlayer = Player::newPlayer(":/resources/resources/playerRight.png", 300, 300, scene);

    this->ennemiVector = new QVector<Ennemi*>();

    for(int i = 0; i < 1; i++){
        Ennemi* ennemi = new Ennemi(":/resources/resources/playerLeft.png", 100,100, scene);
        this->ennemiVector->append(ennemi);
    }

    /*
    //for(int i = 0; i < 1; i++){
        EnnemyIntel* ennemyIntel = new EnnemyIntel(this->ennemiVector->at(0), this->myPlayer);
        //this->ennemiIntelVector->append(ennemyIntel);
        ennemyIntel->start();
    //}
    */



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

#include "game.h"

Game::Game(Scene* scene)
{
    this->scene = scene;
    this->scene->setGame(this);
}

Game::~Game()
{

}

void Game::start()
{
    this->generateMap();
    this->generatePlayer();
}

void Game::generateMap()
{
    this->map = new Map(this->scene);
    this->getMap()->create();
}


void Game::generatePlayer()
{
    this->myPlayer = Player::newPlayer(this->scene);
}

Map* Game::getMap()
{
    return this->map;
}

Player* Game::getPlayer()
{
    return this->myPlayer;
}

void Game::changeMap(QString)
{

}


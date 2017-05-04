#include "game.h"

Game::Game(Scene* scene)
{
    this->scene = scene;
    this->scene->setGame(this);
    this->generateMap();
    this->generatePlayer();
}

Game::~Game()
{

}


void Game::generateMap()
{
    this->map = new Map(this->scene);
    this->createMap();
    this->drawMap();
}

void Game::generatePlayer()
{
    this->myPlayer = Player::newPlayer(this->scene);
    this->drawPlayer();
}

Map* Game::getMap()
{
    return this->map;
}

Player* Game::getPlayer()
{
    return this->myPlayer;
}

void Game::holdTheDoor()
{

}

void Game::createMap()
{
    srand (time(NULL));
    for (int i = 0; i < HEIGH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            this->getMap()->addSol(i, j);
            if(i == 0 && (j == 15 || j == 14 || j == 16))
                this->map->addPorte(i, j, "Gauche");
            else if(i == HEIGH-2 && (j == 15 || j == 14 || j == 16))
                this->map->addPorte(i, j, "Droite");
            else if((i == 13 || i == 14 || i == 15) && j == 0)
                this->map->addPorte(i, j, "Haut");
            else if((i == 13 || i == 14 || i == 15) && j==WIDTH-2)
                this->map->addPorte(i, j, "Bas");
            else if (i == 0 || i == HEIGH-2 || j == 0 || j == WIDTH-2)
                this->map->addMur(i, j);
        }
    }
    this->map->generateObstacle();
}

void Game::drawMap()
{
    for(int i = 0; i < this->map->getBackground()->size(); i++)
        for(int j = 0; j < this->map->getBackground()->at(i)->size(); j++)
            this->scene->addItem(this->map->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem());
}

void Game::drawPlayer()
{
    this->scene->addItem(this->myPlayer->getSprite()->getPixmapItem());
}

void Game::createBarrel(QPointF *mousePos)
{
    new Barrel(mousePos, this->scene);
}



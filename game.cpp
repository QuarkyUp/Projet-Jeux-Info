#include "game.h"

Game::Game(Scene* scene)
{
    this->scene = scene;
    this->scene->setGame(this);
    connect(this->scene, SIGNAL(changeMapEvent(QString)), this, SLOT(changeMap(QString)));
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
    this->QMap = new QVector<Map*>();
    this->currentPosInSpace = new QPoint(0, 0);
    this->QMap->append(new Map(this->scene, this->currentPosInSpace));
    this->currentMap = this->QMap->at(0);
    this->currentMap->create();
}


void Game::generatePlayer()
{
    this->myPlayer = Player::newPlayer(this->scene);
}

Map* Game::getMap()
{
    for (int i = 0; i < this->QMap->size(); ++i)
        if (this->QMap->at(i)->getPosInGame()->rx() == this->currentPosInSpace->rx() && this->QMap->at(i)->getPosInGame()->ry() == this->currentPosInSpace->ry())
            return this->QMap->at(i);
    return NULL;
}

Map *Game::getCurrentMap()
{
    return this->currentMap;
}

Player* Game::getPlayer()
{
    return this->myPlayer;
}

void Game::changeMap(QString str)
{
    if (str == "haut")
    {
        this->getMap()->hideMap();
        this->currentPosInSpace->rx()++;
        this->getPlayer()->getSprite()->getPixmapItem()->setOffset(GAME_SIZE/2 - PIXEL_SIZE, GAME_SIZE - 2*PIXEL_SIZE);
        if (this->getMap() == NULL)
        {
            this->currentMap = new Map(this->scene, this->currentPosInSpace);
            this->currentMap->create();
            this->QMap->append(this->currentMap);
        }
        else
        {
            this->currentMap = this->getMap();
            this->currentMap->drawMap();
        }
    }
    else if (str == "bas")
    {
        this->getMap()->hideMap();
        this->currentPosInSpace->rx()--;
        this->getPlayer()->getSprite()->getPixmapItem()->setOffset(GAME_SIZE/2 - PIXEL_SIZE, 2*PIXEL_SIZE);
        if (this->getMap() == NULL)
        {
            this->currentMap = new Map(this->scene, this->currentPosInSpace);
            this->currentMap->create();
            this->QMap->append(this->currentMap);
        }
        else
        {
            this->currentMap = this->getMap();
            this->currentMap->drawMap();
        }
    }
    else if (str == "gauche")
    {
        this->getMap()->hideMap();
        this->currentPosInSpace->ry()--;
        this->getPlayer()->getSprite()->getPixmapItem()->setOffset(GAME_SIZE - 3*PIXEL_SIZE, GAME_SIZE/2);
        if (this->getMap() == NULL)
        {
            this->currentMap = new Map(this->scene, this->currentPosInSpace);
            this->currentMap->create();
            this->QMap->append(this->currentMap);
        }
        else
        {
            this->currentMap = this->getMap();
            this->currentMap->drawMap();
        }
    }
    else if (str == "droite")
    {
        this->getMap()->hideMap();
        this->currentPosInSpace->ry()++;
        this->getPlayer()->getSprite()->getPixmapItem()->setOffset(2*PIXEL_SIZE, GAME_SIZE/2);
        if (this->getMap() == NULL)
        {
            this->currentMap = new Map(this->scene, this->currentPosInSpace);
            this->currentMap->create();
            this->QMap->append(this->currentMap);
        }
        else
        {
            this->currentMap = this->getMap();
            this->currentMap->drawMap();
        }
    }
}


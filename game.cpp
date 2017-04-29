#include "game.h"

#include <QDebug>
#include <QThread>
#include <QTimer>
#include "croco.h"

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

bool Game::collisionPlayerEnnemy()
{
    for (int i = 0; i < this->getMap()->getBackground()->size(); ++i)
    {
        for (int j =0; j < this->getMap()->getBackground()->at(i)->size(); ++j)
        {
            if (this->getMap()->getBackground()->at(i)->at(j)->getId() == "Mur" ||
                this->getMap()->getBackground()->at(i)->at(j)->getId() == "Porte")
            {
                if (this->getPlayer()->getSprite()->getPixmapItem()->collidesWithItem(this->getMap()->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem()))
                    return true;
            }
        }
    }
    return false;
}


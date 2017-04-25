#include "game.h"

#include <QDebug>

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
    /*
    this->ennemiVector = new QVector<Ennemi*>();
    this->ennemiIntelVector = new QVector<EnnemyIntel*>();
    this->ennemiTimer = new QVector<QTimer*>();

    for(int i = 0; i < 5; i++){
        Ennemi* ennemi = new Ennemi(":/resources/resources/ennemiUp.png", 100*(i+1),100*(i+1), scene);
        //qDebug() << ennemi->getSprite()->getPixmapItem()->sceneBoundingRect().x();
        this->ennemiVector->append(ennemi);

        EnnemyIntel* ennemiIntel = new EnnemyIntel(ennemi, this->myPlayer, this->ennemiVector);
        this->ennemiIntelVector->append(ennemiIntel);



        //QTimer *timer = new QTimer();
        this->ennemiTimer->append(new QTimer());
        connect(this->ennemiTimer->at(i), SIGNAL(timeout()), this->ennemiIntelVector->at(i), SLOT(run()));
        this->ennemiTimer->at(i)->start(15);
    } */

}

Map* Game::getMap()
{
    return this->map;
}

Player* Game::getPlayer()
{
    return this->myPlayer;
}

QVector<Ennemi *> *Game::getEnnemiVector()
{
    return this->ennemiVector;
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


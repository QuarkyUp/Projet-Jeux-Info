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
    //qDebug() << this->myPlayer->getSprite()->getPixmapItem()->sceneBoundingRect();
    //qDebug() << scene->getView()

    this->ennemiVector = new QVector<Ennemi*>();
    this->ennemiIntelVector = new QVector<EnnemyIntel*>();
    this->ennemiTimer = new QVector<QTimer*>();

    for(int i = 0; i < 1; i++){
        Ennemi* ennemi = new Ennemi(":/resources/resources/ennemiUp.png", 100,100, scene);
        qDebug() << ennemi->getSprite()->getPixmapItem()->sceneBoundingRect().x();
        this->ennemiVector->append(ennemi);

        EnnemyIntel* ennemiIntel = new EnnemyIntel(ennemi, this->myPlayer);
        this->ennemiIntelVector->append(ennemiIntel);


        //MARCHE BIEN - NO NEED FIX
        //QTimer *timer = new QTimer();
        this->ennemiTimer->append(new QTimer());
        connect(this->ennemiTimer->at(i), SIGNAL(timeout()), this->ennemiIntelVector->at(i), SLOT(run()));
        this->ennemiTimer->at(i)->start(1000);
    }



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

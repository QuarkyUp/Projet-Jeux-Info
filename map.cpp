#include "map.h"
#include <QDebug>

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Map::Map(Scene* scene, QPoint* pos)
{
    this->scene = scene;
    this->positionInGame = new QPoint(pos->x(), pos->y());
}

Map::~Map()
{
    disconnect(this);
    if (this->timer)
        disconnect(this->timer);
    delete(this->background);
    delete(this->crocoVect);
}


/** ---------- METHODS ---------- **/

void Map::create()
{
    this->background = new QVector<QVector<Element*>*>();
    for (int i = 0; i < HEIGH; ++i)
        this->background->append(new QVector<Element*>());

    this->generateMap();
    this->generateObstacle();
    this->drawMap();
    this->generateEnnemy();

    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(run()));
    connect(this, SIGNAL(noCrocoLeft()), this, SLOT(doNotHoldTheDoor()));
    this->timer->start(15);
}

void Map::drawMap()
{
    for(int i = 0; i < this->getBackground()->size(); i++)
        for(int j = 0; j < this->getBackground()->at(i)->size(); j++)
            this->scene->addItem(this->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem());
}

void Map::hideMap()
{
    for(int i = 0; i < this->getBackground()->size(); i++)
        for(int j = 0; j < this->getBackground()->at(i)->size(); j++)
            this->scene->removeItem(this->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem());
}

void Map::addMur(int i, int j)
{
    this->background->at(i)->replace(j,new Element("Mur", i*PIXEL_SIZE, j*PIXEL_SIZE));
}

void Map::addPorte(int i, int j, QString direction)
{
    if (direction == "Gauche")
        this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, direction));
    if (direction == "Droite")
        this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, direction));
    if (direction == "Haut")
        this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, direction));
    if (direction == "Bas")
        this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, direction));
}

void Map::addSol(int i, int j)
{
    this->background->at(i)->append(new Element("Sol", i*PIXEL_SIZE, j*PIXEL_SIZE));
}

void Map::generateMap()
{
    for (int i = 0; i < HEIGH; ++i)
        for (int j = 0; j < WIDTH; ++j)
        {
            this->addSol(i, j);
            if(i == 0 && (j == 15 || j == 14 || j == 16))
                this->addPorte(i, j, "Gauche");
            else if(i == HEIGH-2 && (j == 15 || j == 14 || j == 16))
                this->addPorte(i, j, "Droite");
            else if((i == 13 || i == 14 || i == 15) && j == 0)
                this->addPorte(i, j, "Haut");
            else if((i == 13 || i == 14 || i == 15) && j==WIDTH-2)
                this->addPorte(i, j, "Bas");
            else if (i == 0 || i == HEIGH-2 || j == 0 || j == WIDTH-2)
                this->addMur(i, j);
        }
}


void Map::generateObstacle()
{
    srand (time(NULL));
    for(int i = 0; i < 30*30; i++)
    {
        int randomX = rand()%(25) + 3;
        int randomY= rand()%(25) + 3;;
        bool isOk = true;

        for (int i = randomX - 3; i < randomX + 3; i++){
            if(!isOk)
                break;
            for (int j = randomY - 3; j < randomY + 3; j++)
                if(this->background->at(i)->at(j)->getId()=="Mur"||this->background->at(i)->at(j)->getId()=="Porte"){
                    isOk = false;
                    break;
                }
        }
        if(isOk)
            this->background->at(randomX)->replace(randomY,new Element("Mur", randomX*PIXEL_SIZE, randomY*PIXEL_SIZE));
    }
}

void Map::generateEnnemy()
{
    srand (time(NULL));
    this->crocoVect = new QVector<Croco*>();
    for (int i = 0; i < rand()%10 + 1; ++i)
        this->crocoVect->append(new Croco(this->scene));
}

/** ---------- SLOT ---------- **/
void Map::doNotHoldTheDoor()
{
    disconnect(this->timer);
    delete(this->timer);

    for (int i = 0; i < this->getBackground()->size(); ++i)
        for (int j = 0; j < this->getBackground()->at(i)->size(); ++j)
            if (this->getBackground()->at(i)->at(j)->getId() == "Porte")
            {
                this->scene->removeItem(this->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem());
                this->getBackground()->at(i)->replace(j, new Element("Sol", i*PIXEL_SIZE, j*PIXEL_SIZE));
                this->scene->addItem(this->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem());
            }
}

void Map::run()
{
    this->emitNoCrocoLeft();
}

/** ---------- SIGNAL ---------- **/

void Map::emitNoCrocoLeft()
{
    if (this->crocoVect->isEmpty())
        emit noCrocoLeft();
}

/** ---------- GETTERS ---------- **/

QVector<QVector<Element*>*>* Map::getBackground()
{
    return this->background;
}

QVector<Croco*>* Map::getCrocoVect()
{
    return this->crocoVect;
}

QPoint *Map::getPosInGame()
{
    return this->positionInGame;
}

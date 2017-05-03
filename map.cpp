#include "map.h"

Map* Map::instance;

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Map::Map()
{
    this->background = new QVector<QVector<Element*>*>();
    for (int i = 0; i < HEIGH; ++i)
        this->background->append(new QVector<Element*>());
}

Map::~Map()
{
    delete(this->background);
}

/** ---------- METHODS ---------- **/

Map* Map::newInstance()
{
    if (Map::instance == NULL)
        Map::instance = new Map();
    return Map::instance;
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


void Map::generateObstacle()
{
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

/** ---------- GETTERS ---------- **/

QVector<QVector<Element*>*>* Map::getBackground()
{
    return this->background;
}

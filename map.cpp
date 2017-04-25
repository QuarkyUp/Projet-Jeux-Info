#include "map.h"
#include <QDebug>

Map* Map::instance;

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Map::Map()
{
    /*
    this->background = new QVector<QVector<Element*>*>();
    this->background->resize(HEIGH);
    for(int i = 0; i < HEIGH; i++){
        //this->background->at(i)->resize(WIDTH);
        for(int j = 0; j < WIDTH; j++)
            this->background->at(i)->append(NULL);
    }
    */
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

void Map::createMap()
{
    //this->background->resize(HEIGH);
    srand (time(NULL));
    for (int i = 0; i < HEIGH; ++i)
    {
        //this->background->at(i)->resize(WIDTH);
        for (int j = 0; j < WIDTH; ++j)
        {
            int random_x;
            random_x = rand() % 100;
            this->background->at(i)->append(new Element("Sol", i*PIXEL_SIZE, j*PIXEL_SIZE));
            if(i == 0 && (j == 15 || j == 14 || j == 16))
                this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, "Gauche"));
            else if(i == HEIGH-2 && (j == 15 || j == 14 || j == 16))
                this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, "Droite"));
            else if((i == 13 || i == 14 || i == 15) && j == 0)
                this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, "Haut"));
            else if((i == 13 || i == 14 || i == 15) && j==WIDTH-2)
                this->background->at(i)->replace(j,new Element("Porte", i*PIXEL_SIZE, j*PIXEL_SIZE, "Bas"));
            else if (i == 0 || i == HEIGH-2 || j == 0 || j == WIDTH-2)
                this->background->at(i)->replace(j,new Element("Mur", i*PIXEL_SIZE, j*PIXEL_SIZE));
        }
    }
    generateObstacle();

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

void Map::drawMap(QGraphicsScene* scene)
{

    for(int i = 0; i < 31; i++){
        for(int j = 0; j < 31; j++)
            this->background->at(i)->at(j)->drawElement(scene);
    }
}

/** ---------- GETTERS ---------- **/

QVector<QVector<Element*>*>* Map::getBackground()
{
    return this->background;
}

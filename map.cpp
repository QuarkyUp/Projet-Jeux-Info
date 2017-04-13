#include "map.h"

Map* Map::instance;

Map::Map()
{
    this->background = new QVector<Element*>();
}

Map::~Map()
{
    delete this->background;
}

Map* Map::newInstance()
{
    if (Map::instance == NULL)
        Map::instance = new Map();
    return Map::instance;
}


void Map::createMap()
{
    for (int i = 0; i < HEIGH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            if ((i == 0 && j == 15) || (i == HEIGH-2 && j == 15) || (i == 15 && j == 0) || (i == 15 && j==WIDTH-2))
                this->background->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE));
            /** HEIGH-2 POUR AFFICHER LES MURS SINON CA DEPASSE **/
            else if (i == 0 || i == HEIGH-2 || j == 0 || j == WIDTH-2)
                this->background->append(new Mur(i*PIXEL_SIZE, j*PIXEL_SIZE));
            else
                this->background->append(new Sol(i*PIXEL_SIZE, j*PIXEL_SIZE));
        }
    }
}

void Map::drawMap(QGraphicsScene* scene)
{

    for(int i = 0; i < this->background->size(); i++)
        this->background->at(i)->drawElement(scene);


}

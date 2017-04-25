#include "map.h"
#include <QDebug>

Map* Map::instance;

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Map::Map()
{
    this->background = new QVector<Element*>();
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
    srand (time(NULL));
    for (int i = 0; i < HEIGH; ++i)
    {
        for (int j = 0; j < WIDTH; ++j)
        {
            int random_x;
            random_x = rand() % 100;

            this->background->append(new Sol(i*PIXEL_SIZE, j*PIXEL_SIZE));

            //Les portes et les murs s'affiches en transparence par dessus le sol
            //gauche
            if(i == 0 && (j == 15 || j == 14 || j == 16))
            {
                this->background->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "gauche"));
                this->background->last()->setStr("Porte");
            }
            //droite
            else if (i == HEIGH-2 && (j == 15 || j == 14 || j == 16))
            {
                this->background->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "droite"));
                this->background->last()->setStr("Porte");
            }
            //haut
            else if ((i == 13 || i == 14 || i == 15) && j == 0)
            {
                this->background->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "haut"));
                this->background->last()->setStr("Porte");
            }
            //bas
            else if ((i == 13 || i == 14 || i == 15) && j==WIDTH-2)
            {
                this->background->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "bas"));
                this->background->last()->setStr("Porte");
            }
            //Obstacles
            else if (i == 0 || i == HEIGH-2 || j == 0 || j == WIDTH-2)
            {
                this->background->append(new Mur(i*PIXEL_SIZE, j*PIXEL_SIZE));
                this->background->last()->setStr("Mur");
            }
            // Trouver une meilleure seed pour avoir des mur/obstacle aléatoire


            else if (random_x < 15 && i > 3 && j > 3 && i < HEIGH - 3 && j < WIDTH - 3)
            {
                this->background->append(new Mur(i*PIXEL_SIZE, j*PIXEL_SIZE));
//                this->background->last()->setStr("Mur");
            }

        }
    }
}

void Map::drawMap(QGraphicsScene* scene)
{

    for(int i = 0; i < this->background->size(); i++)
        this->background->at(i)->drawElement(scene);
}

/** ---------- GETTERS ---------- **/

QVector<Element *> *Map::getBackground()
{
    return this->background;
}

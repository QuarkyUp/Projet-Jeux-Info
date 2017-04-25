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

            /**
            //Les portes et les murs s'affiches en transparence par dessus le sol
            //gauche
            if(i == 0 && (j == 15 || j == 14 || j == 16))
            {
                this->background->at(i)->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "gauche"));
                this->background->at(i)->last()->setStr("Porte");
            }
            //droite
            else if (i == HEIGH-2 && (j == 15 || j == 14 || j == 16))
            {
                this->background->at(i)->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "droite"));
                this->background->at(i)->last()->setStr("Porte");
            }
            //haut
            else if ((i == 13 || i == 14 || i == 15) && j == 0)
            {
                this->background->at(i)->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "haut"));
                this->background->at(i)->last()->setStr("Porte");
            }
            //bas
            else if ((i == 13 || i == 14 || i == 15) && j==WIDTH-2)
            {
                this->background->at(i)->append(new Porte(i*PIXEL_SIZE, j*PIXEL_SIZE, "bas"));
                this->background->at(i)->last()->setStr("Porte");
            }
            //Obstacles
            else if (i == 0 || i == HEIGH-2 || j == 0 || j == WIDTH-2)
            {
                this->background->at(i)->append(new Mur(i*PIXEL_SIZE, j*PIXEL_SIZE));
                this->background->at(i)->last()->setStr("Mur");
            }
            // Trouver une meilleure seed pour avoir des mur/obstacle aléatoire


            else if (random_x < 15 && i > 3 && j > 3 && i < HEIGH - 3 && j < WIDTH - 3)
            {
                this->background->at(i)->append(new Mur(i*PIXEL_SIZE, j*PIXEL_SIZE));
//                this->background->last()->setStr("Mur");
            }
**/
        }
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

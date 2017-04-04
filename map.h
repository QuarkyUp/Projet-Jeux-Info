#ifndef MAP_H
#define MAP_H

#include "element.h"
#include "porte.h"
#include "mur.h"
#include "sol.h"

#include <QVector>
#include <QGraphicsScene>

#define WIDTH 31
#define HEIGH 31
#define PIXEL_SIZE 32

class Map
{
public:
    /** CONSTRUCTOR **/
    Map();

    /** METHODS **/
    static Map* newInstance();
    void createMap();
    void drawMap(QGraphicsScene* scene);

private:
    QVector<Element*>* background;

    static Map* instance;
};

#endif // MAP_H

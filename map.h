#ifndef MAP_H
#define MAP_H

#include "element.h"
#include <QVector>
#include <QGraphicsScene>
#include <QTime>
#include <time.h>



#define WIDTH 31
#define HEIGH 31
#define PIXEL_SIZE 32

class Map
{
public:
    /** CONSTRUCTOR **/
    Map();
    ~Map();

    /** METHODS **/
    static Map* newInstance();
    void createMap();
    void drawMap(QGraphicsScene* scene);

    /** GETTER **/
    QVector<QVector<Element*>*>* getBackground();

private:
    QVector<QVector<Element*>*>* background;

    static Map* instance;
};

#endif // MAP_H

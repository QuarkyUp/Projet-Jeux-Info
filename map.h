#ifndef MAP_H
#define MAP_H

#define WIDTH 31
#define HEIGH 31
#define PIXEL_SIZE 32

#include <QVector>
#include "element.h"

class Map
{
public:
    /** CONSTRUCTOR **/
    Map();
    ~Map();

    /** METHODS **/
    static Map* newInstance();
    void addPorte(int, int, QString);
    void addMur(int, int);
    void addSol(int, int);
    void generateObstacle();

    /** GETTER **/
    QVector<QVector<Element*>*>* getBackground();

private:
    QVector<QVector<Element*>*>* background;

    static Map* instance;
};

#endif // MAP_H

#ifndef MAP_H
#define MAP_H

#define WIDTH 31
#define HEIGH 31
#define PIXEL_SIZE 32

#include <QVector>
#include "element.h"
#include "croco.h"

class Map : public QObject
{
    Q_OBJECT
public:
    /** CONSTRUCTOR **/
    Map(Scene*);
    ~Map();

    /** METHODS **/
    void addPorte(int, int, QString);
    void addMur(int, int);
    void addSol(int, int);
    void generateObstacle();
    void generateEnnemy();

    /** GETTER **/
    QVector<QVector<Element*>*>* getBackground();
    QVector<Croco*>* getCrocoVect();

    /** SIGNAL **/
signals:
    void noCrocoLeft();

private:
    Scene* scene;
    QVector<QVector<Element*>*>* background;
    QVector<Croco*>* crocoVect;
    void emitNoCrocoLeft();
};

#endif // MAP_H

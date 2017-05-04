#ifndef CROCO_H
#define CROCO_H

#include <QObject>
#include <QTimer>
#include "scene.h"
#include "sprite.h"




class Croco : public QObject
{
    Q_OBJECT

public:
    /** CONSTRUCTOR / DESTRUCTOR **/
    Croco(Scene* scene);
    ~Croco();

    /** METHODS **/
    void initialiseCrocoPosition();
    void drawCroco();
    void removeCroco();
    void changeRotation();
    void moveTowardsPlayer();
    void updatePos();
    void move(double, double);

    bool isCollidingWithMap();
    bool isCollidingWithPlayer();

    /** GETTERS **/
    qreal getXpos();
    qreal getYpos();
    Sprite* getSprite();
    QTimer* getTimer();

public slots:
    void run();

private:
    Sprite* crocoSprite;
    Scene* scene;
    QTimer* timer;
    QPoint* current_position;
};

#endif // CROCO_H

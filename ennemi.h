#ifndef ENNEMI_H
#define ENNEMI_H
#include <QGraphicsScene>
#include "personnage.h"
#include "sprite.h"

class Ennemi : public Personnage
{
public:
    static Ennemi* newEnnemi(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
private:
    Ennemi(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
    void drawEnnemi(QGraphicsScene* scene);

    QGraphicsScene* scene;
    static Ennemi* EnnemiInstance;
    Sprite* EnnemiSprite;
};

#endif // ENNEMI_H

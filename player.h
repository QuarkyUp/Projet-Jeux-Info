#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsView>
#include <QKeyEvent>

#include "personnage.h"
#include "sprite.h"

class Player : public Personnage, public QWidget
{
public:
    /** CONSTRUCTOR **/
    static Player* newPlayer(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);

    /** METHODS **/
//    void moveRightPlayer();
//    void moveLeftPlayer();
//    void moveUpPlayer();
//    void moveDownPlayer();
      qreal getXpos();
      qreal getYpos();

    /** GETTERS **/
    Sprite* getSprite();

private:
    Player(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene* scene);
    void drawPlayer(QGraphicsScene* scene);

    QGraphicsScene* scene;
    static Player* playerInstance;
    Sprite* playerSprite;
};

#endif // PLAYER_H

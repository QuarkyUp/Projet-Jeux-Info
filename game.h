#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QString>
#include <QTimer>
#include <QObject>

#include "map.h"
#include "player.h"
#include "ennemi.h"
#include "ennemyintel.h"
#include "croco.h"


class Game: public QObject
{
public:
    /** CONSTRUCTOR **/
    Game();

    /** METHODS **/

    void generateMap(QGraphicsScene* scene);

    void sendKeyboardEvent(QString);

    /** GETTER **/
    Map* getMap();
    Player* getPlayer();
    QVector<Ennemi*>* getEnnemiVector();

private:

    Map* map;
    Player* myPlayer;
    QVector<Ennemi*>* ennemiVector;
    QVector<EnnemyIntel*>* ennemiIntelVector;
    QVector<QTimer*>* ennemiTimer;
};

#endif // GAME_H

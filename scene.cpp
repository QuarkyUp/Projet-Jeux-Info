#include "scene.h"
#include <QDebug>
#include <math.h>
#include <QTransform>


Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);
    this->barrelIntelVector = new QVector<BarrelIntel*>();
    this->barrelVector = new QVector<Item*>();
    this->barrelTimer = new QVector<QTimer*>();
}

void Scene::start()
{
    this->createView();
    this->createGame();
}


void Scene::keyPressEvent(QKeyEvent* event)
{
    /*
    if (event->isAutoRepeat()){
        if (event->key() == Qt::Key_Up)
            this->game->sendKeyboardEvent("UP");
        else if (event->key() == Qt::Key_Down)
            this->game->sendKeyboardEvent("DOWN");
        else if (event->key() == Qt::Key_Left)
            this->game->sendKeyboardEvent("LEFT");
        else if (event->key() == Qt::Key_Right)
            this->game->sendKeyboardEvent("RIGHT");
    }
    */


    if (event->key() == Qt::Key_Space)
    {
        double dx = this->lastMousePosX - game->getPlayer()->getXpos();
        double dy = this->lastMousePosY - game->getPlayer()->getYpos();

        double dist = sqrt(dx*dx + dy*dy);
        double moveX = (dx/dist)*4;
        double moveY = (dy/dist)*4;

        /** POUR ENLEVER/AJOUTER COLLISION AVEC MUR AU MILIEU DE LA MAP IL FAUT COMMENTER/DECOMMENTER LIGNE 88 DANS 'map.cpp' **/
        if((dist > 10))
        {
            game->getPlayer()->getCurrentPos()->setX(game->getPlayer()->getXpos());
            game->getPlayer()->getCurrentPos()->setY(game->getPlayer()->getYpos());
//                qDebug() << *game->getPlayer()->getCurrentPos();
                   game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getXpos()+moveX, game->getPlayer()->getYpos());
                   game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getXpos(), game->getPlayer()->getYpos()+moveY);

                   if (this->collison())
                    game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getCurrentPos()->x(), game->getPlayer()->getCurrentPos()->y());
        }
    }

}

void Scene::mouseMoveEvent  ( QGraphicsSceneMouseEvent * event ){
    this->lastMousePosX = event->scenePos().x();
    this->lastMousePosY = event->scenePos().y();

    qreal mouseRelativeX = event->scenePos().x() - game->getPlayer()->getXpos();
    qreal mouseRelativeY = event->scenePos().y() - game->getPlayer()->getYpos();
    qreal angle = M_PI;

    if((mouseRelativeX > 0) && (mouseRelativeY >= 0))
    {
        angle = atan(mouseRelativeY / mouseRelativeX);
    }
    else if ((mouseRelativeX > 0) && (mouseRelativeY < 0))
    {
        angle = atan(mouseRelativeY / mouseRelativeX) + 2*M_PI;
    }
    else if (mouseRelativeX < 0)
    {
        angle = atan(mouseRelativeY / mouseRelativeX) + M_PI;
    }
    else if ((mouseRelativeX == 0) && (mouseRelativeY > 0))
    {
        angle = M_PI/2;
    }
    else if ((mouseRelativeX == 0) && (mouseRelativeY < 0))
    {
        angle = 3*(M_PI/2);
    }

    QPixmap rotate(game->getPlayer()->getSprite()->getPixmap()->size());
    rotate.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter p(&rotate);
    p.setBackgroundMode(Qt::TransparentMode);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(angle*(180/M_PI) +90);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

    p.drawPixmap(0, 0, *game->getPlayer()->getSprite()->getPixmap());
    p.end();

    game->getPlayer()->getSprite()->getPixmapItem()->setPixmap(rotate);

}

void Scene::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    this->lastMousePosX = event->scenePos().x();
    this->lastMousePosY = event->scenePos().y();
    qreal playerX = game->getPlayer()->getXpos();
    qreal playerY = game->getPlayer()->getYpos();


    Item* barrel = new Item(":/resources/resources/barrel.png", playerX,playerY, this);
    this->barrelVector->append(barrel);

    BarrelIntel* barrelIntel = new BarrelIntel(barrel, this->game->getPlayer(), this->lastMousePosX, this->lastMousePosY);
    this->barrelIntelVector->append(barrelIntel);

    this->barrelTimer->append(new QTimer());
    connect(this->barrelTimer->last(), SIGNAL(timeout()), this->barrelIntelVector->last(), SLOT(run()));
    this->barrelTimer->last()->start(30);
}

void Scene::createView()
{
    this->view = new QGraphicsView(this);

    /** OBLIGER DE FAIRE +2 PIXEL SINON LES SCROLLBARS APPARAISSENT **/
    this->view->setFixedSize(this->width()+2, this->height()+2);
    this->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    this->view->setMouseTracking(true);

    view->show();
}

void Scene::createGame()
{
    this->game = new Game();
    this->game->generateMap(this);
}

QGraphicsView* Scene::getView()
{
    return this->view;
}

Game* Scene::getGame()
{
    return this->game;
}

bool Scene::collison()
{
    for (int i = 0; i < game->getMap()->getBackground()->size(); ++i)
    {
        //qDebug() << game->getMap()->getBackground()->at(i)->getStr();
        if (game->getMap()->getBackground()->at(i)->getStr() == "Mur")
        {
            //qDebug() << "Test colliding item";
            if (game->getPlayer()->getSprite()->getPixmapItem()->collidesWithItem(game->getMap()->getBackground()->at(i)->getSprite()->getPixmapItem()))
            {
                qDebug() << "COLLISION AVEC UN MUR";
                return true;
            }
        }
    }

    return false;
}

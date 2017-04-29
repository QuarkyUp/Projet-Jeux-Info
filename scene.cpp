#include "scene.h"
#include <QDebug>
#include <QTransform>
#include <cmath>
#include "barrel.h"
#include "game.h"

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);

    this->mvt = new QVector<bool>();
    for (int i = 0; i < 5; ++i)
        this->mvt->append(false);

    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(updateKey()));
    timer->start(30);

}
Scene::~Scene()
{
    delete(this->mvt);
}

/** ---------- METHODS ---------- **/

void Scene::start()
{
    this->createView();
    this->createGame();
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

void Scene::updateOrientation()
{


    qreal mouseRelativeX = this->lastMousePosX - game->getPlayer()->getXpos();
    qreal mouseRelativeY = this->lastMousePosY - game->getPlayer()->getYpos();
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

void Scene::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Z && !event->isAutoRepeat())
    {
       this->mvt->replace(0, true);
    }
    if (event->key() == Qt::Key_S && !event->isAutoRepeat())
    {
        this->mvt->replace(1, true);
    }
    if (event->key() == Qt::Key_Q && !event->isAutoRepeat())
    {
        this->mvt->replace(2, true);
    }
    if (event->key() == Qt::Key_D && !event->isAutoRepeat())
    {
      this->mvt->replace(3, true);
    }
    /*
    if (event->key() == Qt::Key_Space)
    {
        double dx = this->lastMousePosX - game->getPlayer()->getXpos();
        double dy = this->lastMousePosY - game->getPlayer()->getYpos();

        double dist = sqrt(dx*dx + dy*dy);
        double moveX = (dx/dist)*4;
        double moveY = (dy/dist)*4;

        if((dist > 10))
        {
            game->getPlayer()->getCurrentPos()->setX(game->getPlayer()->getXpos());
            game->getPlayer()->getCurrentPos()->setY(game->getPlayer()->getYpos());

            game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getXpos()+moveX, game->getPlayer()->getYpos()+moveY);

            if (this->collisonMur())
                game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getCurrentPos()->x(), game->getPlayer()->getCurrentPos()->y());
        }
    } */
}

void Scene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Z && !event->isAutoRepeat())
    {
       this->mvt->replace(0, false);
    }
    if (event->key() == Qt::Key_S && !event->isAutoRepeat())
    {
        this->mvt->replace(1, false);
    }
    if (event->key() == Qt::Key_Q && !event->isAutoRepeat())
    {
        this->mvt->replace(2, false);
    }
    if (event->key() == Qt::Key_D && !event->isAutoRepeat())
    {
      this->mvt->replace(3, false);
    }
}

void Scene::mouseMoveEvent  ( QGraphicsSceneMouseEvent * event )
{
    this->lastMousePosX = event->scenePos().x();
    this->lastMousePosY = event->scenePos().y();
    this->updateOrientation();
}

void Scene::mouseReleaseEvent( QGraphicsSceneMouseEvent* event )
{
    qreal playerX = game->getPlayer()->getXpos();
    qreal playerY = game->getPlayer()->getYpos();

    Barrel* barrel= new Barrel(":/resources/resources/barrel.png", playerX, playerY, event->scenePos(), this, this->game->getPlayer());
}

/** ---------- SLOTS ---------- **/

void Scene::updateKey()
{
        if (this->mvt->at(0))
        {
            this->game->getPlayer()->moveUp(this->getGame()->getMap());
            this->updateOrientation();
        }
        if (this->mvt->at(1))
        {
            this->game->getPlayer()->moveDown(this->getGame()->getMap());
            this->updateOrientation();
        }
        if (this->mvt->at(2))
        {
            this->game->getPlayer()->moveLeft(this->getGame()->getMap());
            this->updateOrientation();
        }

        if (this->mvt->at(3))
        {
            this->game->getPlayer()->moveRight(this->getGame()->getMap());
            this->updateOrientation();
        }
}

QGraphicsView* Scene::getView()
{
    return this->view;
}

Game* Scene::getGame()
{
    return this->game;
}

#include "scene.h"
#include "game.h"
#include "barrel.h"

#include <QDebug>

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);
    this->start();
}
Scene::~Scene()
{
    delete(this->mvt);
}

/** ---------- METHODS ---------- **/

void Scene::start()
{
    this->createView();
    this->createMvtTimer();
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
    this->game->generateMap();
}


void Scene::setGame(Game * game)
{
    this->game = game;
}

void Scene::updateOrientation()
{
    qreal mouseRelativeX = this->lastMousePosX - this->game->getPlayer()->getXpos();
    qreal mouseRelativeY = this->lastMousePosY - this->game->getPlayer()->getYpos();
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

void Scene::createMvtTimer()
{
    this->mvt = new QVector<bool>();
    for (int i = 0; i < 5; ++i)
        this->mvt->append(false);

    this->mvtTimer = new QTimer();
    connect(this->mvtTimer, SIGNAL(timeout()), this, SLOT(updateKey()));
    connect(this, SIGNAL(changeMapEvent(QString)), this->game, SLOT(changeMap(QString)));
    this->mvtTimer->start(30);
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
//    this->game->createBarrel(new QPointF(event->scenePos()));
    new Barrel(new QPointF(event->scenePos()), this);
}

/** ---------- SLOTS ---------- **/

void Scene::updateKey()
{
        if (this->mvt->at(0))
        {
            this->game->getPlayer()->moveUp();
            this->updateOrientation();
        }
        if (this->mvt->at(1))
        {
            this->game->getPlayer()->moveDown();
            this->updateOrientation();
        }
        if (this->mvt->at(2))
        {
            this->game->getPlayer()->moveLeft();
            this->updateOrientation();
        }

        if (this->mvt->at(3))
        {
            this->game->getPlayer()->moveRight();
            this->updateOrientation();
        }
}

/** ---------- GETTERS ---------- **/

QGraphicsView* Scene::getView()
{
    return this->view;
}

Game* Scene::getGame()
{
    return this->game;
}

/** ---------- SIGNAL ---------- **/

void Scene::emitChangeMapEvent()
{
    if (this->getGame()->getPlayer()->getYpos() < 0)
        emit this->changeMapEvent("haut");
    else if (this->getGame()->getPlayer()->getYpos() > GAME_SIZE)
        emit this->changeMapEvent("bas");
    else if (this->getGame()->getPlayer()->getXpos() < 0)
        emit this->changeMapEvent("gauche");
    else if (this->getGame()->getPlayer()->getXpos() > GAME_SIZE)
        emit this->changeMapEvent("droite");
}

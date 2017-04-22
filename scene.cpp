#include "scene.h"
#include <QDebug>
#include <math.h>
#include <QTransform>


Scene::Scene()
{
    this->setSceneRect(0, 0 , GAME_SIZE, GAME_SIZE);
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

        if((dist > 10))
        {
            game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getXpos()+moveX, game->getPlayer()->getYpos());
            game->getPlayer()->getSprite()->getPixmapItem()->setOffset(game->getPlayer()->getXpos(), game->getPlayer()->getYpos()+moveY);
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
    /*
    QTransform trans;
    trans.translate(game->getPlayer()->getXpos(), game->getPlayer()->getYpos()).rotate(angle*(180/M_PI), Qt::ZAxis);
    game->getPlayer()->getSprite()->getPixmapItem()->setTransformOriginPoint(game->getPlayer()->getSprite()->getPixmapItem()->boundingRect().center());
    game->getPlayer()->getSprite()->getPixmapItem()->setRotation(angle*(180/M_PI));
    */
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


/*
void Scene::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_Left:
            this->game->sendKeyboardEvent("LEFT");
            break;
        case Qt::Key_Right:
            this->game->sendKeyboardEvent("RIGHT");
            break;
        case Qt::Key_Up:
            this->game->sendKeyboardEvent("UP");
            break;
        case Qt::Key_Down:
            this->game->sendKeyboardEvent("DOWN");
            break;
    }
}

void Scene::keyReleaseEvent(QKeyEvent *event) {
    if (!event->isAutoRepeat()) {
        switch(event->key()) {
            case Qt::Key_Left:
                this->game->sendKeyboardEvent("LEFT");
                break;
            case Qt::Key_Right:
                this->game->sendKeyboardEvent("RIGHT");
                break;
            case Qt::Key_Up:
                this->game->sendKeyboardEvent("UP");
                break;
            case Qt::Key_Down:
                this->game->sendKeyboardEvent("DOWN");
                break;
        }
    }
}
*/

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
    this->game = new Game(this);
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

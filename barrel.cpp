#include "barrel.h"

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/
Barrel::Barrel(QPointF *mousePos, Scene *scene)
{
    this->scene = scene;
    this->player = this->scene->getGame()->getPlayer();
    this->mousePos = mousePos;

    this->sprite = new Sprite(":/resources/resources/barrel.png", this->player->getXpos(), this->player->getYpos());
    this->drawBarrel();

    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(run()));
    this->timer->start(15);
}

Barrel::~Barrel()
{
    this->removeBarrel();
    disconnect(this->timer);
}

/** ---------- METHODS ---------- **/

void Barrel::drawBarrel()
{
    this->scene->addItem(this->sprite->getPixmapItem());
}

void Barrel::removeBarrel()
{
    this->scene->removeItem(this->sprite->getPixmapItem());
}

void Barrel::changeRotation()
{
    qreal playerRelativeX = this->getXpos() - this->mousePos->x();
    qreal playerRelativeY = this->getYpos() - this->mousePos->y();
    qreal angle = M_PI;

    if((playerRelativeX > 0) && (playerRelativeY >= 0))
    {
        angle = atan(playerRelativeY / playerRelativeX);
    }
    else if ((playerRelativeX > 0) && (playerRelativeY < 0))
    {
        angle = atan(playerRelativeY / playerRelativeX) + 2*M_PI;
    }
    else if (playerRelativeX < 0)
    {
        angle = atan(playerRelativeY / playerRelativeX) + M_PI;
    }
    else if ((playerRelativeX == 0) && (playerRelativeY > 0))
    {
        angle = M_PI/2;
    }
    else if ((playerRelativeX == 0) && (playerRelativeY < 0))
    {
        angle = 3*(M_PI/2);
    }

    QPixmap rotate(this->getSprite()->getPixmap()->size());
    rotate.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter p(&rotate);
    p.setBackgroundMode(Qt::TransparentMode);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(angle*(180/M_PI) + 90);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

    p.drawPixmap(0, 0, *this->getSprite()->getPixmap());
    p.end();
    this->getSprite()->getPixmapItem()->setPixmap(rotate);
}

void Barrel::moveTowardsMouse()
{
    double dx = this->getXpos() - this->mousePos->x();
    double dy = this->getYpos() - this->mousePos->y();

    double dist = sqrt(dx*dx + dy*dy);
    double moveX = (dx/dist)*(-4);
    double moveY = (dy/dist)*(-4);

    if (this->rotation){
        changeRotation();
        this->rotation = false;
    }
    if(dist > 10 && !this->isCollidingWith(this->scene->getGame()->getMap()))
    {
        changeRotation();
        this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+moveX, this->getYpos()+moveY);
    }
    else
    {
        delete(this);
    }
}

bool Barrel::isCollidingWith(Map* map)
{
    for (int i = 0; i < map->getBackground()->size(); ++i)
    {
        for (int j =0; j < map->getBackground()->at(i)->size(); ++j)
        {
            if (map->getBackground()->at(i)->at(j)->getId() == "Mur" ||
                map->getBackground()->at(i)->at(j)->getId() == "Porte")
            {
                if (this->getSprite()->getPixmapItem()->collidesWithItem(map->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem()))
                    return true;
            }
        }
    }
    return false;
}

/** ---------- SLOTS ---------- **/

void Barrel::run()
{
    moveTowardsMouse();
}

/** ---------- GETTERS ---------- **/

qreal Barrel::getXpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().x();
}

qreal Barrel::getYpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().y();
}

Sprite* Barrel::getSprite()
{
    return this->sprite;
}

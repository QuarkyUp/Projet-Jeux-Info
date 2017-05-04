#include "croco.h"
#include "game.h"
#include "player.h"

/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/

Croco::Croco(Scene* scene)
{
    this->scene = scene;

    this->initialiseCrocoPosition();
    this->getSprite()->getPixmapItem()->setShapeMode(QGraphicsPixmapItem::BoundingRectShape);
    this->drawCroco();

    this->current_position = new QPoint(this->getSprite()->getPixmapItem()->sceneBoundingRect().x(), this->getSprite()->getPixmapItem()->sceneBoundingRect().y());

    this->timer = new QTimer();
    connect(this->timer, SIGNAL(timeout()), this, SLOT(run()));
    this->timer->start(15);
}

Croco::~Croco()
{
    this->removeCroco();
    disconnect(this->timer);
}

/** ---------- METHODS ---------- **/

void Croco::initialiseCrocoPosition()
{
    int posX, posY;
    do
    {
        posX = rand() % GAME_SIZE;
        posY = rand() % GAME_SIZE;
        this->crocoSprite = new Sprite(":/resources/resources/ennemiUp.png", posX, posY);
    }
    while (this->isCollidingWithMap());
}

void Croco::drawCroco()
{
    this->scene->addItem(this->crocoSprite->getPixmapItem());
}

void Croco::removeCroco()
{
    this->scene->removeItem(this->crocoSprite->getPixmapItem());
}

void Croco::changeRotation()
{
    qreal playerRelativeX = this->getXpos() - this->scene->getGame()->getPlayer()->getXpos();
    qreal playerRelativeY = this->getYpos() - this->scene->getGame()->getPlayer()->getYpos();
    qreal angle = M_PI;

    if((playerRelativeX > 0) && (playerRelativeY >= 0))
        angle = atan(playerRelativeY / playerRelativeX);
    else if ((playerRelativeX > 0) && (playerRelativeY < 0))
        angle = atan(playerRelativeY / playerRelativeX) + 2*M_PI;
    else if (playerRelativeX < 0)
        angle = atan(playerRelativeY / playerRelativeX) + M_PI;
    else if ((playerRelativeX == 0) && (playerRelativeY > 0))
        angle = M_PI/2;
    else if ((playerRelativeX == 0) && (playerRelativeY < 0))
        angle = 3*(M_PI/2);

    QPixmap rotate(this->getSprite()->getPixmap()->size());
    rotate.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter p(&rotate);
    p.setBackgroundMode(Qt::TransparentMode);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(angle*(180/M_PI) - 90);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

    p.drawPixmap(0, 0, *this->getSprite()->getPixmap());
    p.end();
    this->getSprite()->getPixmapItem()->setPixmap(rotate);
}

void Croco::moveTowardsPlayer()
{
    double dx = this->scene->getGame()->getPlayer()->getXpos() - this->getXpos();
    double dy = this->scene->getGame()->getPlayer()->getYpos() - this->getYpos();

    double dist = sqrt(dx*dx + dy*dy);
    double moveX = (dx/dist);
    double moveY = (dy/dist);

    this->changeRotation();

    if (!this->isCollidingWithPlayer())
    {
        if (!this->isCollidingWithMap())
            this->move(moveX, moveY);
    }
}

bool Croco::isCollidingWithMap()
{
    for (int i = 0; i < this->scene->getGame()->getMap()->getBackground()->size(); ++i)
        for (int j =0; j < this->scene->getGame()->getMap()->getBackground()->at(i)->size(); ++j)
            if (this->scene->getGame()->getMap()->getBackground()->at(i)->at(j)->getId() == "Mur" || this->scene->getGame()->getMap()->getBackground()->at(i)->at(j)->getId() == "Porte")
                if (this->getSprite()->getPixmapItem()->collidesWithItem(this->scene->getGame()->getMap()->getBackground()->at(i)->at(j)->getSprite()->getPixmapItem()))
                    return true;
    return false;
}

bool Croco::isCollidingWithPlayer()
{
    return this->getSprite()->getPixmapItem()->collidesWithItem(this->scene->getGame()->getPlayer()->getSprite()->getPixmapItem());
}

void Croco::updatePos()
{
    this->current_position->setX(this->getXpos());
    this->current_position->setY(this->getYpos());
}

void Croco::move(double x, double y)
{
    this->updatePos();
    this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+x, this->getYpos()+y);
    if (this->isCollidingWithMap())
    {
        this->getSprite()->getPixmapItem()->setOffset(this->current_position->x(), this->current_position->y());
        this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+1, this->getYpos());
        if (this->isCollidingWithMap())
        {
            this->getSprite()->getPixmapItem()->setOffset(this->current_position->x(), this->current_position->y());
            this->getSprite()->getPixmapItem()->setOffset(this->getXpos()-1, this->getYpos());
            if (this->isCollidingWithMap())
            {
                this->getSprite()->getPixmapItem()->setOffset(this->current_position->x(), this->current_position->y());
                this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()+1);
                if (this->isCollidingWithMap())
                {
                    this->getSprite()->getPixmapItem()->setOffset(this->current_position->x(), this->current_position->y());
                    this->getSprite()->getPixmapItem()->setOffset(this->getXpos(), this->getYpos()-1);
                    if (this->isCollidingWithMap())
                        this->getSprite()->getPixmapItem()->setOffset(this->current_position->x(), this->current_position->y());
                }
            }
        }
    }
}

/** ---------- SLOTS ---------- **/

void Croco::run()
{
    this->moveTowardsPlayer();
}

/** ---------- GETTERS ---------- **/

qreal Croco::getXpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().x();
}

qreal Croco::getYpos()
{
    return this->getSprite()->getPixmapItem()->sceneBoundingRect().y();
}

Sprite* Croco::getSprite()
{
    return this->crocoSprite;
}

QTimer* Croco::getTimer()
{
    return this->timer;
}

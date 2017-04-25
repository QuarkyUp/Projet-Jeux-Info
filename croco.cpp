#include "croco.h"


/** ---------- CONSTRUCTOR / DESTRUCTOR ---------- **/

Croco::Croco(QString imagePath, qreal coordX, qreal coordY, QGraphicsScene *scene, Player* player)
{
    this->crocoSprite = new Sprite(imagePath, coordX, coordY);
    this->player = player;
    this->scene = scene;
    this->timer = new QTimer();
    this->drawCroco();

    connect(this->timer, SIGNAL(timeout()), this, SLOT(run()));
    this->timer->start(15);
}

Croco::~Croco()
{
    removeCroco();
    disconnect(this->timer);
    delete(this->timer);
}

/** ---------- METHODS ---------- **/

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
    qreal playerRelativeX = this->getXpos() - this->player->getXpos();
    qreal playerRelativeY = this->getYpos() - this->player->getYpos();
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
    double dx = this->player->getXpos() - this->getXpos();
    double dy = this->player->getYpos() - this->getYpos();

    double dist = sqrt(dx*dx + dy*dy);
    double moveX = (dx/dist);
    double moveY = (dy/dist);

    if(dist > 60)
    {
        changeRotation();
        this->getSprite()->getPixmapItem()->setOffset(this->getXpos()+moveX, this->getYpos()+moveY);
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

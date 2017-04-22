#include "barrelintel.h"

BarrelIntel::BarrelIntel(Item* barrel, Player* player, qreal mousePosX, qreal mousePosY)
{
    this->barrel = barrel;
    this->player = player;
    this->mousePosX = mousePosX;
    this->mousePosY = mousePosY;
}

void BarrelIntel::run()
{
    moveTowardsMouse();


}

void BarrelIntel::moveTowardsMouse()
{
    double dx = this->barrel->getXpos() - this->mousePosX;
    double dy = this->barrel->getYpos() - this->mousePosY;

    double dist = sqrt(dx*dx + dy*dy);
    double moveX = (dx/dist)*(-4);
    double moveY = (dy/dist)*(-4);

    if (this->rotation){
        changeRotation();
        this->rotation = false;
    }
    if(dist > 10)
    {
        changeRotation();
        this->barrel->getSprite()->getPixmapItem()->setOffset(this->barrel->getXpos()+moveX, this->barrel->getYpos());
        this->barrel->getSprite()->getPixmapItem()->setOffset(this->barrel->getXpos(), this->barrel->getYpos()+moveY);
    }
    //else
        //this->scene->barrelTimer->removeOne()
        //barrel->scene->removeItem(barrel->getSprite()->getPixmapItem());
}

void BarrelIntel::changeRotation()
{
    qreal playerRelativeX = this->barrel->getXpos() - this->mousePosX;
    qreal playerRelativeY = this->barrel->getYpos() - this->mousePosY;
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

    QPixmap rotate(this->barrel->getSprite()->getPixmap()->size());
    rotate.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter p(&rotate);
    p.setBackgroundMode(Qt::TransparentMode);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(angle*(180/M_PI) + 90);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

    p.drawPixmap(0, 0, *this->barrel->getSprite()->getPixmap());
    p.end();
    this->barrel->getSprite()->getPixmapItem()->setPixmap(rotate);
}

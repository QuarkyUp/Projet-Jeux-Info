#include "ennemyintel.h"
#include <math.h>


EnnemyIntel::EnnemyIntel(Ennemi* ennemi, Player* player, QVector<Ennemi*>* ennemiVector)
{
    this->ennemi = ennemi;
    this->player = player;
    this->ennemiVector = ennemiVector;
}

void EnnemyIntel::run()
{
        //ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos()+10, ennemi->getYpos());
        moveTowardsPlayer();
}

// Mauvais Référentiel
void EnnemyIntel::moveTowardsPlayer()
{
    double dx = this->player->getXpos() - this->ennemi->getXpos();
    double dy = this->player->getYpos() - this->ennemi->getYpos();

    double dist = sqrt(dx*dx + dy*dy);
    double moveX = (dx/dist)*1;
    double moveY = (dy/dist)*1;

    bool isMoveOkay = true;
    QList<QGraphicsItem *> list = this->ennemi->getSprite()->getPixmapItem()->collidingItems();
    list.removeOne(this->ennemi->getSprite()->getPixmapItem());

    for (int i = 0; i < list.length(); i++){
        if(this->ennemi->getSprite()->getPixmapItem()->collidesWithItem(list.at(i)))
        {
            isMoveOkay = false;

        }
    }

    if((dist > 60))
    {
        changeRotation();
        ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos()+moveX, ennemi->getYpos());
        ennemi->getSprite()->getPixmapItem()->setOffset(ennemi->getXpos(), ennemi->getYpos()+moveY);
    }
}

void EnnemyIntel::changeRotation()
{
    qreal playerRelativeX = this->ennemi->getXpos() - this->player->getXpos();
    qreal playerRelativeY = this->ennemi->getYpos() - this->player->getYpos();
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

    QPixmap rotate(this->ennemi->getSprite()->getPixmap()->size());
    rotate.fill(QColor::fromRgb(0, 0, 0, 0));
    QPainter p(&rotate);
    p.setBackgroundMode(Qt::TransparentMode);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
    p.translate(rotate.size().width() / 2, rotate.size().height() / 2);
    p.rotate(angle*(180/M_PI) - 90);
    p.translate(-rotate.size().width() / 2, -rotate.size().height() / 2);

    p.drawPixmap(0, 0, *this->ennemi->getSprite()->getPixmap());
    p.end();
    this->ennemi->getSprite()->getPixmapItem()->setPixmap(rotate);
}

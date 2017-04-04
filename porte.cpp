#include "porte.h"

Porte::Porte(qreal x, qreal y)
{
    /** IL FAUT AJOUTER L'IMAGE DE LA PORTE **/
    //this->sprite = new Sprite(":/resources/resources/porte.png", x, y);
    Element::sprite = new Sprite(":/resources/resources/sol.png", x, y);
}

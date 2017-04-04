#include "element.h"

Element::Element()
{

}

void Element::drawElement(QGraphicsScene* scene)
{
    scene->addItem(this->sprite->getPixmapItem());
}

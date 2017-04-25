#ifndef MUR_H
#define MUR_H

#include "element.h"
#include "sprite.h"

class Mur : public Element
{
public:
    /** CONSTRUCTOR **/
    Mur(qreal, qreal);

    /** GETTERS **/
    QString className();
};

#endif // MUR_H

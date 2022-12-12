#include "other.h"

Other::Other()
{
    setFlag(QGraphicsItem::ItemIsSelectable);
}

int Other::type() const
{
    return Type;
}

#ifndef SHOP_H
#define SHOP_H
#include "other.h"
#include "card.h"
#include "nutwall.h"
#include "rednutwall.h"
#include "bignutwall.h"
class Shop : public Other
{
    int counter;
    int time;
    int rand;
public:
    Shop();
    int nutNum;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void addPlant(QString s,QPointF pos);
};

#endif // SHOP_H

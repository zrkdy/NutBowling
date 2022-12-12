#include "shop.h"

Shop::Shop()
{

}

QRectF Shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap("://pvz图片/Shop.png"));
}

void Shop::addPlant(QString s,QPointF pos)
{
    switch (Card::map[s])
    {
        case 0:{
            NutWall *nut1 = new NutWall;
            nut1->setPos(pos.x(),pos.y()+30);
            scene()->addItem(nut1);
            break;
        }
        case 1:{

            redNutWall *nut2 = new redNutWall;
            nut2->setPos(pos.x(),pos.y()+30);
            scene()->addItem(nut2);
            break;
        }
        case 2:{

            bigNutWall *nut3 = new bigNutWall;
            nut3->setPos(pos.x(),pos.y()-30);
            scene()->addItem(nut3);
            break;
        }
    }
}

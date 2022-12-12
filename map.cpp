#include "map.h"
#include "shop.h"
Map::Map()
{
    dragOver = false;
    setAcceptDrops(true);
}

QRectF Map::boundingRect() const
{
    return QRectF(-369, -235, 238, 470);
}

void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->setPen(Qt::red);
    painter->drawRect(-131,-235,1,478);
}

void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasText())
    {
        event->setAccepted(true);
        dragOver = true;
        update();
    }
    else
        event->setAccepted(false);
}

void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    QString s = event->mimeData()->text();
    if (event->mimeData()->hasText())
    {
        QPointF pos = mapToScene(event->pos());
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 290);
        pos.setY((int(pos.y()) - 81) / 98 * 98 + 160);
        Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
        shop->addPlant(s,pos);
    }
    update();
}

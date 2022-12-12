#include "bomb.h"

bomb::bomb()
{
    atk = 1000;
    movie=nullptr;
    setMovie("://pvz图片/Boom.gif");
}

QRectF bomb::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void bomb::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items2 = collidingItems();
    foreach (QGraphicsItem *item, items2){
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
        zombie->hp -= atk;
        if (zombie->hp <= 0)
        {
            zombie->state = 3;
            zombie->setMovie("://pvz图片/Burn.gif");
        }
    }
}

bool bomb::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && QLineF(pos(), other->pos()).length() < 160;
}

void bomb::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}


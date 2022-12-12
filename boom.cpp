#include "boom.h"

boom::boom()
{
    movie=nullptr;
    //atk = 1800;
    setMovie("://pvz图片/Boom.gif");
}

boom::~boom()
{

}

void boom::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    painter->drawImage(QRectF(-70, -100, 200, 200), image);
}

QRectF boom::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void boom::advance(int phase)
{
    if (!phase)
        return;
    update();

    QList<QGraphicsItem *> items = collidingItems();
    foreach (QGraphicsItem *item, items)
    {
        Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
        zombie->hp=0;
        if (zombie->hp <= 0)
        {
            zombie->state = 3;
            zombie->setMovie("://pvz图片/Burn.gif");
        }
    }
    delete this;
}

void boom::sleep(int msec)
{
    QDateTime last=QDateTime::currentDateTime();
    QDateTime now;
    while(1){
        now=QDateTime::currentDateTime();
        if(last.msecsTo(now)>=msec){
            break;
        }
    }
}

bool boom::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && QLineF(pos(), other->pos()).length() < 160;
}

void boom::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

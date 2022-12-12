#include "bigNutWall.h"
bigNutWall::bigNutWall()
{

    movie=nullptr;
    speed=1.2*1.5*1.8*3*80.0 * 33 / 1000 / 4;
    setMovie(":/pvz图片/bignutwall1.gif");
}

bigNutWall::~bigNutWall()
{
    delete movie;

}

QRectF bigNutWall::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void bigNutWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    painter->drawImage(QRectF(-70, -100, 150, 150), image);
}

bool bigNutWall::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{

    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qAbs(other->y()+30-y())<50 && qAbs(other->x() - x()) < 50;
}

void bigNutWall::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

void bigNutWall::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        //flag = true;
        foreach (QGraphicsItem *item, items)
        {
            Zombie *zombie = qgraphicsitem_cast<Zombie *>(item);
            zombie->hp = 0;

        }
    }
    setX(x() + speed);
    if (x() > 1100)
        delete this;
}

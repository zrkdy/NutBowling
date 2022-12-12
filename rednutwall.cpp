#include "rednutwall.h"

redNutWall::redNutWall()
{
    movie=nullptr;
    speed=1.2*1.3*1.6*1.5*3*80.0 * 33 / 1000 / 4;
    setMovie("://pvz图片/rednutwall.gif");
}

redNutWall::~redNutWall()
{
    delete movie;

}

QRectF redNutWall::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

void redNutWall::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QImage image = movie->currentImage();
    painter->drawImage(QRectF(-70, -100, 90, 90), image);
}

bool redNutWall::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Zombie::Type && qAbs(other->y()+30-y())<50 && qAbs(other->x() - x()) < 50;
}

void redNutWall::setMovie(QString path)
{
    if (movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}

void redNutWall::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        this->speed = 0;
        this->hide();
        boom *b = new boom;
        b->setPos(this->x(),this->y()-60);
        scene()->addItem(b);
        delete this;
        return;

    }
    setX(x() + speed);
    if (x() > 1100)
        delete this;
}

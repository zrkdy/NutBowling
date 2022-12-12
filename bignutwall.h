#ifndef BIGNUTWALL_H
#define BIGNUTWALL_H


#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QtWidgets>

#include "zombie.h"
#include "other.h"

class bigNutWall : public QGraphicsItem
{
public:
    bigNutWall();
    qreal speed;
    ~bigNutWall() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path);
    void advance(int phase) override;
protected:
    QMovie *movie;
};

#endif // BIGNUTWALL_H

#ifndef REDNUTWALL_H
#define REDNUTWALL_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QtWidgets>

#include "zombie.h"
#include "other.h"
#include "boom.h"
class redNutWall : public QGraphicsItem
{
public:
    redNutWall();
    int atk;
    qreal speed;
    bool flag;
    bool y_flag;
    qreal y_initial;
    ~redNutWall() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path);
    void advance(int phase) override;
protected:
    QMovie *movie;
};

#endif // NUTWALL_H

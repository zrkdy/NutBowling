#ifndef NUTWALL_H
#define NUTWALL_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QtWidgets>

#include "zombie.h"
#include "other.h"
class NutWall : public QGraphicsItem
{
public:
    NutWall();
    qreal speed;
    bool y_flag;
    qreal y_speed;
    qreal y_initial;
    ~NutWall() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path);
    void advance(int phase) override;
protected:
    QMovie *movie;
};

#endif // NUTWALL_H

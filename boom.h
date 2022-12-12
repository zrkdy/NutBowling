#ifndef BOOM_H
#define BOOM_H
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QtWidgets>

#include "zombie.h"
#include "other.h"

class boom : public QGraphicsItem
{
public:
    boom();
    ~boom() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path);
    void advance(int phase) override;
    void sleep(int msec);
protected:
    QMovie *movie;
};

#endif // BOOM_H

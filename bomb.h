#ifndef BOMB_H
#define BOMB_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QtWidgets>

#include "zombie.h"
#include "other.h"
class bomb : public QGraphicsItem
{
public:
    QMovie *movie;
    int atk;
    bomb();
    ~bomb();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    void setMovie(QString path);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // BOMB_H

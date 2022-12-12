#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>

class Zombie : public QGraphicsItem
{
public:
    QVector<int> a;
    int hp;
    int atk;
    int state;
    qreal speed;
    enum { Type = UserType + 2};
    Zombie();
    ~Zombie() override;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    int type() const override;
    void setMovie(QString path);
    void setHead(QString path);
protected:
    QMovie *movie;
    QMovie *head;
};

#endif // ZOOMBIE_H

#ifndef CARD_H
#define CARD_H

#include "other.h"
#include "shop.h"
#include "map.h"
#include "pvzplayscene.h"
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QVector>
using namespace std;
extern int cardidx;

class Card : public Other
{
public:

    struct bb{
        Card *card;
        int x;
    };
    int orz;
    int pos;
    QString text;
    bool flag;
    qreal speed;
    Card(QString s);
    Card(int a);
    const static QMap<QString, int> map;
    const static QVector<QString> name;
    void deleteCard();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    bb* re_sets();
private:
};
#endif // CARD_H

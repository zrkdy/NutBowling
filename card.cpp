#include "card.h"

using namespace std;
Card::bb cardlist[10];
int cardidx=0;
int num[10] = {1,0,0,0,0,0,0,0,0,0};
int nutnum;

const QMap<QString, int> Card::map = {{"NutWall", 0}, {"redNutWall", 1}, {"bigNutWall", 2}};
const QVector<QString> Card::name = {"NutWall","redNutWall","bigNutWall"};

Card::Card(QString s)
{
    orz=1;
    text = s;
    speed = 3;

    nutnum++;
    cardlist[cardidx].card=this;
    cardlist[cardidx++].x=1;
}

Card::Card(int a)
{
    orz=a;
}

QRectF Card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap("://pvz图片/Card.png"));
    if(text=="NutWall"){
        painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap("://pvz图片/WallNut.png"));
    }
    else if(text=="redNutWall"){
        painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap("://pvz图片/rednutwall.png"));
    }
    else if(text=="bigNutWall"){
        painter->scale(1.5, 1.5);
        painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap("://pvz图片/bigWallNut.png"));
    }
}
void Card::advance(int phase)
{
    if (!phase)
        return;
    update();
}


void Card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton)).length()
            < QApplication::startDragDistance())
        return;
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    if(text=="NutWall"){
        QImage image("://pvz图片/WallNut.png");
        mime->setText(text);
        mime->setImageData(image);
        drag->setMimeData(mime);
        drag->setPixmap(QPixmap::fromImage(image));
        drag->setHotSpot(QPoint(35, 35));
        drag->exec();
        setCursor(Qt::ArrowCursor);
        if(drag->exec()){
            deleteCard();
        }
    }
    else if(text=="redNutWall"){
        QImage image("://pvz图片/rednutwall.png");
        mime->setText(text);
        mime->setImageData(image);
        drag->setMimeData(mime);
        drag->setPixmap(QPixmap::fromImage(image));
        drag->setHotSpot(QPoint(35, 35));
        drag->exec();
        setCursor(Qt::ArrowCursor);
        if(drag->exec()){
            deleteCard();
        }
    }
    else if(text=="bigNutWall"){
        QImage image("://pvz图片/bigWallNut.png");
        mime->setText(text);
        mime->setImageData(image);
        drag->setMimeData(mime);
        drag->setPixmap(QPixmap::fromImage(image));
        drag->setHotSpot(QPoint(35, 35));
        drag->exec();
        setCursor(Qt::ArrowCursor);
        if(drag->exec()){
            deleteCard();
        }
    }

}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //releaseMouse();
    Q_UNUSED(event)
    setCursor(Qt::ArrowCursor);
}

Card::bb *Card::re_sets()
{
    return cardlist;
}



void  Card::deleteCard(){


    this->orz=0;
    //delete this;

    for(int i=0;i<nutnum;i++){
            if(cardlist[i].card->orz==0){
                cardlist[i].x=0;
                break;
            }

        }

    nutnum--;
    delete this;

}


